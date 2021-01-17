#include <stdio.h>
#include <stdlib.h>
#include <AnfrunsDenis.h>

/* Enunciat.
 Fer un algoritme per portar la puntuació d’un equip de futbol a la lliga. Aquest algoritme demanarà deu resultats de deu partits,
 seguint el format de local – visitant, on el nostre equip començarà jugant com a local i anirà alternant a visitant. Si l’equip guanya,
 anotarem tres punts. Si empata, un i si perd, cap punt. Al final s’ha de mostrar el número de punts assolits per l’equip. Depenent del
 número de punts que l’equip assoleixi a aquesta minilliga, l’equip pot pujar de categoria, mantenir la categoria o baixar de categoria,
 segons la següent taula:
*/

// prototipos



int main() {
    SetConsoleTitle("Dossier Tema 3.1 Exercici 04. (Categoria equip) Denis Anfruns.");
    // Tildes y símbolos alienígenas.
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);

    int golsLocals, golsVisitants;
    int punts=0, jornada;

    /// Inicio del ejercicio
    for (jornada=1;jornada<=10:++jornada){
        demanarPuntuacioJornada(&golsLocals,&golsVisitants,jornada);
        punts=punts+calculPunts(golsLocals,golsVisitants,jornada);
    }

    resetPrograma();
    return 0;
}

int demanarPuntuacioJornada(int *golsLocals,&golsVisitants,jornada){
    int g1, g2;
    printf("Jornada %d",jornada);
    printf("Gols equip local: ");
    scanf("%d",&g1);
    printf("Gols equip visitant: ");
    scanf("%d",&g2);
    punts=calculPunts(&jornada,&g1,&g2);

    return punts;
}

int calculPunts(*g1,*g2){

}
