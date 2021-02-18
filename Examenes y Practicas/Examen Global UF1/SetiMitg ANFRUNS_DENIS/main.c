#include "ANFRUNSDENIS.h"
#include <stdio.h>
#include <stdlib.h>

#define MAXVECTOR 48

bool volsJugar();
void glaDosIA(float ptsGlaDosIA,int *pc);
void marcarBaralles(int v1[],char v2[]);
void moureCartes(int v1[],char v2[],int qttE,int pos);
void imprimirBaralla(int v1[],char v2[],int qttE);
void guardarNumBaralla(int v[],int qttE);
void guardarPalBaralla(char v[],int qttE);
void registreTorns(int v1[],char v2[],int v3[],char v4[],int numCarta);
void resultat(float ptsUsuari,float ptsOrdinador);
void imprimirRegistre(int v1[],char v2[]);
void indexAleatori(int v1[],int qttE,int *numCarta,int cont);

// Funciones nuevas del examen.
float comprobarCartes(int v1[],char v2[],int v3[],char v4[],int num1, int *cartaEsp);
void cartaEspecial(int numCartaEsp,int qttE,int numCarta,int cont,int v1[],char v2[],int v3[],char v4[]);

int main() {
    SetConsoleTitle("1ra Práctica Global. (Set i Mitg) Denis Anfruns.");

    //tildes
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    //números aleatorios.
    srand(time(NULL));

    start();
    return 0;
}

void start() {
    ///////////////////////////////////////
    // Baraja principal
    int numBaralla[MAXVECTOR];
    char palBaralla[MAXVECTOR];

    ///////////////////////////////////////
    // Registro de jugadores.
    int numUsu[MAXVECTOR],numOrd[MAXVECTOR];
    char palUsu[MAXVECTOR],palOrd[MAXVECTOR];
    float ptsUsu=0,ptsOrd1=0;
    bool usuari=true;
    int ordinador=0;
    ///////////////////////////////////////
    int torn=0, ronda=1, carta, cartaEsp=0;

    guardarNumBaralla(numBaralla,MAXVECTOR);                                                    //guardo los números y palos de las cartas.
    guardarPalBaralla(palBaralla,MAXVECTOR);                                                    //guardo los números y palos de las cartas.
    imprimirBaralla(numBaralla,palBaralla,MAXVECTOR);                                           //cabecera-baraja del juego.                                                                                                //usuario decide si quiere jugar.
    marcarBaralles(numUsu,palUsu);                                                              //marco la baraja del jugador.
    marcarBaralles(numOrd,palOrd);                                                              //marco la baraja del ordenador.

    while((usuari || ordinador==0) && numBaralla[0]!=-1) {                                      //controlo si el usuario sigue jugando o no.
        if(usuari){
            printf("\n\n RONDA %d: \n La teva puntuació es de %.1f punts.\n",ronda,ptsUsu);
            usuari=volsJugar();                                                                 //usuario decide si quiere jugar.
        }
        if(usuari){                                                                             //controlo si el usuario sigue jugando o no.
            ++torn;                                                                             //controlo los turnos (que no las rondas) para hacer el cálculo de cartas que debo restar a la baraja.
            carta=rand()%MAXVECTOR-torn;                                                        //usuario pide carta y suma puntos.
            registreTorns(numBaralla,palBaralla,numUsu,palUsu,carta);                           //registro de los turnos del usuario.                                                        //nou aleatori per la carta especial.
            if(palUsu[0]=='Z'){
                cartaEspecial(cartaEsp,MAXVECTOR,carta,torn,numUsu,palUsu,numOrd,palOrd);
            }
            ptsUsu=comprobarCartes(numBaralla,palBaralla,numUsu,palUsu,carta,&cartaEsp);
            moureCartes(numBaralla,palBaralla,MAXVECTOR,carta);                                 //controlo la carta sacada y organizo la baraja.
        }
        glaDosIA(ptsOrd1,&ordinador);                                                           //ordenador decide si quiere jugar.
        if(ordinador==0){                                                                       //controlo si el ordenador sigue jugando o no.
            ++torn;                                                                             //controlo los turnos para hacer el cálculo de cartas que debo restar a la baraja.
            carta=rand()%MAXVECTOR-torn;                                                        //ordenador pide carta y suma puntos.

            registreTorns(numBaralla,palBaralla,numOrd,palOrd,carta);                           //registro de los turnos del ordenador.
            moureCartes(numBaralla,palBaralla,MAXVECTOR,carta);                                 //controlo la carta sacada y organizo la baraja.
        }
        ++ronda;
    }
    if(numBaralla[0]==-1) {
        // me quedé aquí claudina, estaba revisando con el print el porqué me entraba el programa en esta función y no sé porque veo que me la ha liado en la baraja en este punto.
        imprimirBaralla(numBaralla,palBaralla,MAXVECTOR);
        printf("\n\n S'han acabat les cartes de la baralla.");
    }
    resultat(ptsUsu,ptsOrd1);
    printf("\n\n Cartes del Usuari:\n");
    imprimirRegistre(numUsu,palUsu);
    printf("\n Cartes del Ordinador:\n");
    imprimirRegistre(numOrd,palOrd);
    resetPrograma();
}

void cartaEspecial(int numCartaEsp,int qttE,int numCarta,int cont,int v1[],char v2[],int v3[],char v4[]){
    int i=0,posUsu=0,posOrd=0,indexUsu,indexOrd;
    int intAux;
    char charAux;

    //miro el registro del usuario.
    if(numCartaEsp==1){
        while(i<qttE && v1[posUsu]!=-1){
            ++posUsu;
        }
        indexUsu=rand()%posUsu;
    }
    //miro el registro del ordenador.
    if(numCartaEsp==1){
        while(i<qttE && v3[posOrd]!=-1){
            ++posOrd;
        }
        indexOrd=rand()%posOrd;
        //si el usuario no tiene cartas (compruebo el índice 0) entonces la carta especial no hace efecto.
        if(v3[0]==-1){
            //Intercambio de los números.
            intAux=v3[indexOrd];
            v3[indexOrd]=v1[indexUsu];
            v1[indexUsu]=intAux;
            //intercambio de los palos.
            charAux=v3[indexOrd];
            v3[indexOrd]=v1[indexUsu];
            v1[indexUsu]=charAux;
        }
    }
    if(numCartaEsp==2){
        // efecto de la carta 2
    }
}

float comprobarCartes(int v1[],char v2[],int v3[],char v4[],int num1, int *cartaEsp){
    float pts=0,ptsAcum=0;
    int pos=0;

    printf("\n Has tret la carta %d-%c",v1[num1],v2[num1]);
    if(v2[num1]=='Z'){
        printf("\n Es una carta especial!");
        switch (v1[(num1)]) {
            case 1: *cartaEsp=1; break;
            case 2: *cartaEsp=2; break;
        }
    }
    if(v4[num1]!='Z'){
        while(v3[pos]!=-1){
            switch (v3[(pos)]) {
                case 1: pts=1; break;
                case 2: pts=2; break;
                case 3: pts=3; break;
                case 4: pts=4; break;
                case 5: pts=5; break;
                case 6: pts=6; break;
                case 7: pts=7; break;
                case 10: pts=0.5; break;
                case 11: pts=0.5; break;
                case 12: pts=0.5; break;
        }
        ++pos;
        ptsAcum=ptsAcum+pts;
        }
    }
    return ptsAcum;
}

void marcarBaralles(int v1[],char v2[]){
    marcaIntV(v1,MAXVECTOR,-1);
    marcaCharV(v2,MAXVECTOR,'X');
}

void resultat(float ptsUsuari,float ptsOrdinador) {
    printf("\n\n PUNTUACIÓ USUARI: %.1f  PUNTUACIÓ ORDINADOR %.1f",ptsUsuari,ptsOrdinador);
    bool jug=false,pc=false;

    if(ptsUsuari>7.5){
        jug=true;
    }
    if(ptsOrdinador>7.5){
        pc=true;
    }

    if((jug && pc) || (ptsUsuari==ptsOrdinador)){
        printf("\n RESULTAT: ");
        setColor(YELLOW); printf("EMPAT"); setColor(7);
    }

    if(ptsUsuari<=7.5 && pc==true) {
        printf("\n RESULTAT: ");
        setColor(YELLOW); printf("GUANYA L'USUARI"); setColor(7);
    } else if (ptsOrdinador<=7.5 && jug==true){
        printf("\n RESULTAT: ");
        setColor(YELLOW); printf("GUANYA L'ORDINADOR"); setColor(7);
    }

    if(ptsUsuari<=7.5 && ptsUsuari>ptsOrdinador) {
        printf("\n RESULTAT: ");
        setColor(YELLOW); printf("GUANYA L'USUARI"); setColor(7);
    } else if (ptsOrdinador<=7.5 && ptsOrdinador>ptsUsuari) {
        printf("\n RESULTAT: ");
        setColor(YELLOW); printf("GUANYA L'ORDINADOR"); setColor(7);
    }
}

void imprimirRegistre(int v1[],char v2[]){
    int pos=0;
    printf("\t");
    while(v1[pos]!=-1){
        printf(" %d-%c\t",v1[pos],v2[pos]);
        ++pos;
    }
}

bool volsJugar() {
    char selection;

    do {
        printf(" Vols carta usuari? (s/n):");
        setColor(YELLOW);
        scanf("%c",&selection);
        setColor(7);
        fflush(stdin);
    } while (selection!='s' && selection!='S' && selection!='n' && selection!='N');
    if(selection=='s' || selection=='S') {
        return true;
    } else {
        return false;
    }
}

void glaDosIA(float ptsGlaDosIA,int *pc) {
    int cond=0;
    if(ptsGlaDosIA>5) {
        cond=rand()%1;
        if(cond==1) *pc=1;
        if(ptsGlaDosIA>7) {
            *pc=1;
        }
    }
}

void registreTorns(int v1[],char v2[],int v3[],char v4[],int numCarta) {
    int pos=0;

    //recorro el vector en busca de un hueco donde meter el valor de la carta del turno actual.
    //números de la baraja/vector del jugador/ordenador.
    //si la carta sacada de la baraja contiene una Z entonces nola registro.
    while(v3[pos]!=-1 && v2[numCarta]!='Z') {
        ++pos;
    }
    if(v3[pos]==-1 && v2[numCarta]!='Z') v3[pos]=v1[numCarta];
    if(v4[pos]=='X' && v2[numCarta]!='Z') v4[pos]=v2[numCarta];
}

void imprimirBaralla(int v1[],char v2[],int qttE) {
    int i=0;

    printf("\n BENVINGUT AL JOC DEL SET I MITG\n");
    printf(" ===============================\n");
    for(; i<qttE; ++i) {
        printf(" %d-%c\t",v1[i],v2[i]);
        if(i==9 || i==19 || i==29 || i==39) printf("\n");
    }
}

void moureCartes(int v1[],char v2[],int qttE,int pos) {
    int posAux=pos;

    //marco con -1 y 'X' el hueco que queda en la baraja para no tener que recorrer los
    //vector 1. números.
    while(pos<qttE) { //reorganizo el vector 1.
        v1[pos]=v1[pos+1];
        ++pos;
    }
    if(v1[qttE-1]!=-1) v1[qttE-1]=-1; //v1. la primera vez que se saca carta marco la última posición después de reorganizar.
    //vector 2. palos.
    while(posAux<qttE) {
        v2[posAux]=v2[posAux+1];
        ++posAux;
    }
    if(v2[qttE-1]!='X') v2[qttE-1]='X'; //v2. la primera vez que se saca carta marco la última posición después de reorganizar.
}

void guardarNumBaralla(int v[],int qttE) {
    int i=0,j=1,k=1;

    for(; i<qttE; ++i, ++j) {
        if(i<=39){
            v[i]=j;
        } else if (i>= 40 && i<=43){
           v[i]=k;
        } else {
            v[i]=k+1;
        }
        if(j==7) {
            j=9;
        }
        if(j==12) {
            j=0;
        }
    }
}

void guardarPalBaralla(char v[],int qttE) {
    int i=0;
    char j='O';

    while (i<qttE) {
        v[i]=j;
        ++i;
        if(i==10) j='E';
        if(i==20) j='C';
        if(i==30) j='B';
        if(i==40) j='Z';
    }
}



