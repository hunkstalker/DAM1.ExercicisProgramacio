#include <stdio.h>
#include <stdlib.h>
#include <rlutil.h>
#include <stdbool.h>
#include <time.h>

bool musicPlay=false;

// Método para reproducir música.
void music(){
    PlaySound(TEXT("artblock"), NULL, SND_LOOP | SND_ASYNC);
}

// INICI PROGRAMA
int main(){

    srand(time(NULL));
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);

    char optionPr='X';
    int caudal=0, caudalAnterior=300;


    // Ejecuta la música 1 vez.
    if (musicPlay){
        music();
        musicPlay=false;
    }

    SetConsoleTitle("Practica 1 Exercici 3. Embassament.");

    // Caudal aleatorio
    int azar=rand()%2;
    if (azar==0) caudal=caudalAnterior+rand()%11*caudalAnterior/100;
    else caudal=caudalAnterior-rand()%11*caudalAnterior/100;

    // INICIO PROGRAMA

    setColor(6);
    printf("\n BENVINGUTS AL SISTEMA DE CONTROL DE L'EMBASSAMENT DE VALLFORNERS");
    printf("\n DENIS ANFRUNS\n");
    setColor(15);

    printf("Introdueix el cabal inicial de l'embassament (0-1500):\n");
    printf("Introdueix la capacitat inicial del riu 1 (0-400):\n");
    printf("Introdueix la capacitat inicial del riu 2 (0-400):\n");


    // FIN PROGRAMA

    // SALIDA DEL PROGRAMA
    setColor(15);
    fflush(stdin);
    printf("\n>> Ara vols ["); setColor(12); printf("R"); setColor(WHITE); printf("]epetir l'exercici o vols ["); setColor(12); printf("S"); setColor(WHITE); printf("]ortir? ");
    scanf("%c",&optionPr);
    fflush(stdin);
    // Compr. errores
    while (!(optionPr=='R' || optionPr=='r' || optionPr=='S' || optionPr=='s')){
		printf(">> Vols ["); setColor(12); printf("R"); setColor(WHITE); printf("]epetir l'exercici o vols ["); setColor(12); printf("S"); setColor(WHITE); printf("]ortir? ");
		scanf("%c",&optionPr);
		fflush(stdin);
    }
    if (optionPr=='R' || optionPr=='r'){
        cls();
        main();
    } else {
        setColor(6);
        printf("\nDossier UF1. Tema 2.3, Exercici 29, Curs 2020/2021 Denis Anfruns. EDUCEM, Granollers."); setColor(15); printf("\n>> Prem Intro per sortir...");
        getchar();
        exit(0);
    }
    return 0;
}


