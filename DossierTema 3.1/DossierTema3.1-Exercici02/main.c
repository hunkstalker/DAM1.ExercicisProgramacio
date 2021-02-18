#include <stdio.h>
#include <stdlib.h>
#include <rlutil.h>
#include <time.h>

/* Enunciat.
 Fer un algoritme per poder jugar al TRIO. Aquest joc tracta de triar tres números del 0 al 9.
 Llavors el sistema genera la combinació guanyadora de tres números. Cal mostrar per pantalla quants
 encerts ha tingut l’usuari. S’ha de fer servir únic procediment per tal de generar la combinació guanyadora i
 un altre per a obtenir els tres nombres de l’usuari. Els nombres tant de l’usuari com de la combinació
 guanyadora no es poden repetir. Per a calcular el nombre d’encerts, no cal que els nombres estiguin en
 la mateixa posició, simplement cal que siguin iguals.
*/

// prototipos
void resetPrograma(void);

void demanarNumUsu(int *usu1, int *usu2, int *usu3);
void demanarNumOrd(int *ord1, int *ord2, int *ord3);
int demanarNum(int min, int max);
int comprovarEncerts(int usu1,int usu2,int usu3,int ord1,int ord2,int ord3);

int main() {
    SetConsoleTitle("Dossier Tema 3.1 Exercici 02. (Trio) Denis Anfruns.");

    // Tildes y símbolos alienígenas.
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    srand(time(NULL));

    /// Inicio del ejercicio
    int usu1, usu2, usu3, ord1, ord2, ord3, encerts;

    printf("\n");
    demanarNumUsu(&usu1,&usu2,&usu3);
    demanarNumOrd(&ord1,&ord2,&ord3);

    printf ("\n >> Valors de l'usauri: %d-%d-%d",usu1,usu2,usu3);
    printf ("\n >> Valors de l'ordinador: %d-%d-%d",ord1,ord2,ord3);

    encerts=comprovarEncerts(usu1,usu2,usu3,ord1,ord2,ord3);
    printf("\n\n >> El total d'encerts es: %d",encerts);

    resetPrograma();
    return 0;
}

int demanarNum(int min, int max) {
    int numUsu;
    do {
        printf(" >> Introdueix un valor entre %d i %d: ",min,max);
        setColor(GREEN);
        scanf("%d",&numUsu);
        setColor(7);
    } while(numUsu<min || numUsu>max);
    return numUsu;
}

void demanarNumUsu(int *usu1, int *usu2, int *usu3) {
    *usu1=demanarNum(0,9);
    do {
        *usu2=demanarNum(0,9);
    } while (*usu1==*usu2);

    do {
        *usu3=demanarNum(0,9);
    } while (*usu1==*usu3 || *usu2==*usu3);
}

void demanarNumOrd(int *ord1, int *ord2, int *ord3) {
    *ord1=rand()%10;
    do {
        *ord2=rand()%10;
    } while(*ord1==*ord2);

    do {
        *ord3=rand()%10;
    } while(*ord1==*ord3 || *ord2==*ord3);
}

int comprovarEncerts(int usu1,int usu2,int usu3,int ord1,int ord2,int ord3) {
    int encerts=0;

    if(usu1==ord1 || usu1==ord2 || usu1==ord3) encerts++;
    if(usu2==ord1 || usu2==ord2 || usu2==ord3) encerts++;
    if(usu3==ord1 || usu3==ord2 || usu3==ord3) encerts++;
    return encerts;
}

/// Reset programa.
void resetPrograma() {

    char optionPr='X';      // Variable para controlar la salida/repetición del programa.
    int finalCountdown=1;   // I'ts a final countdown!

    // RESET.
    fflush(stdin);
    setColor(15); printf("\n\n >> Ara vols [");
    setColor(12); printf("R");
    setColor(15); printf("]einiciar el sistema o vols [");
    setColor(12); printf("S");
    setColor(15); printf("]ortir? ");
    scanf("%c",&optionPr);
    fflush(stdin);

    // Compr. errores
    while (!(optionPr=='R' || optionPr=='r' || optionPr=='S' || optionPr=='s')) {
        setColor(RED);
        printf(" >> ¡Error!");
        setColor(15); printf(" Vols [");
        setColor(12); printf("R");
        setColor(15); printf("]einiciar el sistema o vols [");
        setColor(12); printf("S");
        setColor(15); printf("]ortir? ");
        scanf("%c",&optionPr);
        fflush(stdin);
    }
    if (optionPr=='R' || optionPr=='r') {
        cls();
        main();
    } else {
        setColor(6);
        printf("\n Curs.2020/2021. Denis Anfruns. EDUCEM, Granollers.");
        setColor(15);

        // Cuenta atrás.
        printf("\n\n El programa es tancara en: ");
        printf("%d",finalCountdown);
        for (finalCountdown=finalCountdown-1; finalCountdown>=0; finalCountdown--) {
            msleep(1000);
            printf("\b%d",finalCountdown);
        }
        msleep(500);
        exit(0);
    }
}
