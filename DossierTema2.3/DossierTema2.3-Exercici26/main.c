#include <stdio.h>
#include <stdlib.h>
#include <rlutil.h>

/* Dossier UF1, Tema 2.3 Exercici XX.

(Mastermind)
Fer un algoritme que donat una s�rie de nombres naturals introdu�ts per l'usuari,
indiqui si aquesta s�rie �s creixent (cada nombre �s major o igual que l'anterior), no creixent
(hi ha un nombre que no �s igual o major que l'anterior) o decreixent (tots els nombres s�n iguals o
m�s petits que l'anterior). La s�rie de nombres acaba quan l'usuari introdueix un 0 (zero)
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
N�meros introdu�ts: 3 3 6 7 8 8 0
Resposta: S�rie creixent

N�meros introdu�ts: 3 3 6 7 6 8 0
Resposta: S�rie no creixent

N�meros introdu�ts: 3 3 2 2 1 0
Resposta: S�rie decreixent

N�meros introdu�ts: 3 3 3 0
Resposta: La s�rie no creix ni decreix

Procediment: demana els dos primers n�meros abans d�entrar en el bucle i determina si la seq��ncia amb aquests dos n�meros est� pujant o baixant.
El cas que siguin iguals l�haur�s de tractar com a cas especial
Seguidament dins del bucle cerca quines s�n les condicions que fan que tant creixent com decreixent canv�in d�estat

*/
