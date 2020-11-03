#include <stdio.h>
#include <stdlib.h>
#include <rlutil.h>
#include <time.h>

/* Dossier UF1, Tema 2.3 Exercici 29.

(Mastermind)
Fer un algoritme que generi un nombre aleatori de 4 xifres.
L'usuari llavors ha d'introduir nombres de 4 xifres fins que l'encerti o be hagi fet n intents.
El nombre d'intents també els ha d'introduir l'usuari. A cada nombre de 4 xifres que introdueixi l'usuari,
el programa li ha de dir si el nombre que ha d'endevinar és més gran o més petit. Si l'usuari
l'encerta en un nombre de vegades menor que n, llavors ha guanyat. Si no, ha perdut.
*/

// INICI PROGRAMA
int main(){

    SetConsoleTitle("Dossier UF1, Tema 2.3 Exercici 29.");

    int i=0, attemps=0, nSecret=0, numUsu=0;
    char optionPr='X';

	srand(time(NULL));
	for (i=0;i<9999;i++){
        nSecret=rand()%9999;
	}
	printf(">> Numero aleatori a esbrinar: "); setColor(GREEN); printf("%d", nSecret); setColor(WHITE);


	while (attemps<1){
        setColor(6);
        printf("\n\n>> Quants intents vols fer?: "); setColor(15);
        scanf("%d",&attemps);
        fflush(stdin);
        while (attemps<1){
            setColor(RED);
            printf("\n>> No pots fer 0 intents, minim 1."); setColor(WHITE); printf("\n\n>> Quants intents vols fer?: ");
            scanf("%d",&attemps);
            fflush(stdin);
        }
	}

	printf(">> Numero d'intents introduit per l'usuari: "); setColor(GREEN); printf("%d",attemps); setColor(WHITE);

    while (attemps>0){
        setColor(6);
        printf("\n\n>> Prova d'esbrinar el numero: "); setColor(15);
        scanf("%d",&numUsu);
        fflush(stdin);
        if (numUsu!=nSecret){
            setColor(15);
            printf(">> El nombre introduit es el: "); setColor(RED); printf("%d", numUsu); setColor(15); printf(" y es"); setColor(RED); printf(" INCORRECTE."); setColor(15);
            attemps--;
            if (attemps!=0){
                printf("\n>> Et quedan "); setColor(RED); printf("%d", attemps); setColor(15); printf(" intents.");
            }
        } else {
            printf(">> El nombre introduit es el: "); setColor(GREEN); printf("%d", numUsu); setColor(15); printf(" y es"); setColor(GREEN); printf(" CORRECTE.\n");
            attemps=-1;
        }
    }
    if (attemps==0){
        printf("\n\n>> S'han terminat els intent/s.\n");
    }

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

/* Exemple:
Número aleatori a esbrinar: 1456
Número d’intents (introduït per l’usuari): 5
Intent usuari: 5000
Resposta Ordinador: Més petit
Intent usuari: 2500
Resposta Ordinador: Més petit
Intent Usuari: 1250
Resposta Ordinador: Més gran
Intent Usuari: 1400
Resposta Ordinador: Més gran
Intent Usuari: 1450
Resposta Ordinador: Has perdut!, Has esgotat tots els intents
*/
