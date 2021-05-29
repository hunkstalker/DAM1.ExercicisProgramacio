#include "ANFRUNSDENIS.h"
#include <stdio.h>
#include <stdlib.h>

#define MAXVECTOR 40
//#define MAXCADENA 50


void resultat(float puntuacioJugador, float puntuacioOrdenador, int nJug, char palJug, int nOrd, char palOrd, int qttJug, int qttOrd,);

int main() {
    SetConsoleTitle("Correción Examen");

    //tildes
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    //números aleatorios.
    //srand(time(NULL));

    start();
    return 0;
}

void start() {
    // VECTORES
    char palBaralla[MAXVECTOR],palJug[MAXVECTOR],palOrd[MAXVECTOR];
    int nBaralla[MAXVECTOR],nJug[MAXVECTOR],nOrd[MAXVECTOR];
    int qttB=MAXVECTOR;

    // NO VECTORES
    int qttJug=0,qttOrd=0;
    int numCarta;
    char palCarta;

    bool continuaJugador=true,continuaOrdenador=true;
    float puntuacioJugador=0,puntuacioOrdenador=0;

    omplirPal(palBaralla,qttB);
    omplirNum(nBaralla,qttB);
    pintarBaralla(nBaralla,palBaralla,qttB);

    while((continuaJugador || continuaOrdenador) && qttB>0){
        if(continuaJugador==true){
            continuaJugador=preguntaUsu();
            if(continuaJugador==true){
                robaCarta(palBaralla,nBaralla,&qttE,&palCarta,&numCarta);
                desaCarta(palCarta,numCarta,&qttJug,nJug,palJug);
                puntuacioJugador=actualizarPunts(numCarta);
            }
        }
        if(continuaOrdenador==true){
            continuaOrdenador=inteligenciaOrd(puntuacioOrdenador);
            if(continuaOrdenador==true){
                robaCarta(palBaralla,nBaralla,&qttE,&palCarta,&numCarta);
                desaCarta(palCarta,numCarta,&qttOrd,nOrd,palOrd);
                puntuacioJugador=actualizarPunts(numCarta);
            }
        }
    }
    resultat(puntuacioJugador,puntuacioOrdenador,nJug,palJug,nOrd,palOrd,qttJug,qttOrd,);
    resetPrograma();
}

void omplirPal(char palBaralla[] int qttB) {
    char pals[4]='OBCE';

    for(i=0; i<qttB; i++) {
        palBaralla[i]=pals[i/10];
    }
}

void omplirNum(int nBaralla[] int qttB) {
    int i, j=0;

    /// REPASAR
    for(i=1; i<qttB; i++){
        nBaralla[j]=i;
        ++j;
        if(j==7) j=10;
    } else if (j==13) i=1;
}

void pintarBaralla(nBaralla,palBaralla,qttB) {

    if(i%10==0 && i!=0) printf("\n");
    printf("%d - %c\t",nBaralla[i],palBaralla[i]);
}

bool preguntaUsuari(){
    bool continua=true;
    char resposta;

    do {
        fflush(stdin);
        printf("Vols continua jugan?");
        scanf("%c",&resposta);
        fflush(stdin);
    } while(resposta1='s' && resposta!='n');

    if(resposta=='n') continua=false;

    return continua;
}

void robaCarta(int nBaralla[], char palBaralla[], int *qttB, int *palCarta, char *numCarta){
    int pos;

    pos=rand()%(*qttB);
    *numCarta=nBaralla[pos];
    *palCarta=palBaralla[pos];
    --(*qttB);
}

float actualizarPuntos(int numCarta){
    float punts;

    if(numCarta<=7 puntos=numCarta);
    else puntos=0.5;

    return
}

bool inteligenciaOrd(float puntuacioOrdenador){
    bool continua=true;
    int probabilidad;

    if(puntuacioOrdenador>=7.5) continua=false;
    else if(puntuacioOrdenador>5 && puntuacioOrdenador<7.5){
        probabilidad=rand()%2;
        if(probabilidad==0)continua==false;
    }

    return continua;
}

void resultat(float puntuacioJugador, float puntuacioOrdenador, int nJug, char palJug,nOrd,palOrd,qttJug,qttOrd,){


    if(puntuacioJugador>7.5 && puntuacioOrdenador>7.5) printf("Empate");
    else if(puntuacioJugador>7.5 && puntuacioOrdenador<=7.5) printf("Ordenador");
    else if(puntuacioJugador<=7.5 && puntuacioOrdenador>7.5) printf("Jugador");
    else if(puntuacioJugador==puntuacioOrdenador) printf("Empate");
    else if(puntuacioJugador>puntuacioOrdenador>7.5) printf("Jugador");
    else printf("Ordenador");
}


