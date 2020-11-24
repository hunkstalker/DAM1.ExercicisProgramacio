#include <stdio.h>
#include <stdlib.h>
#include <rlutil.h>

/* Dossier UF1, Tema 2.3 Exercici XX.

(Mastermind)
Fer un algoritme que donat una sèrie de nombres naturals introduïts per l'usuari,
indiqui si aquesta sèrie és creixent (cada nombre és major o igual que l'anterior), no creixent
(hi ha un nombre que no és igual o major que l'anterior) o decreixent (tots els nombres són iguals o
més petits que l'anterior). La sèrie de nombres acaba quan l'usuari introdueix un 0 (zero)
*/

// INICI PROGRAMA
int main(){

    SetConsoleTitle("Dossier UF1, Tema 2.3 Exercici 26.");

    char optionPr='x';

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
Números introduïts: 3 3 6 7 8 8 0
Resposta: Sèrie creixent

Números introduïts: 3 3 6 7 6 8 0
Resposta: Sèrie no creixent

Números introduïts: 3 3 2 2 1 0
Resposta: Sèrie decreixent

Números introduïts: 3 3 3 0
Resposta: La sèrie no creix ni decreix

Procediment: demana els dos primers números abans d’entrar en el bucle i determina si la seqüència amb aquests dos números està pujant o baixant.
El cas que siguin iguals l’hauràs de tractar com a cas especial
Seguidament dins del bucle cerca quines són les condicions que fan que tant creixent com decreixent canvïin d’estat

*/
