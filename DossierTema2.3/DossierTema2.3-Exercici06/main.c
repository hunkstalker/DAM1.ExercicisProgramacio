#include <stdio.h>
#include <stdlib.h>

/* Dossier UF1. Tema 2.3 Exercici 6

6.(><)
Fer un algoritme que demani a l'usuari dos nombres naturals i un caràcter,
que pot ser ‘>’ o ‘<’. Llavors, l'algoritme ha de mostrar per pantalla tots els
nombres naturals entre els dos introduïts, ordenats de menor a major si el caràcter
és ‘>’ o de major a menor si el caràcter és ‘<’
*/

int main()
{
    int num1=0, num2=0, aux=0;;
    char car='a';

    printf(">> Digues si vols que sigui > (ascendent) o < (descendent). ");
    scanf("%c",&car);
    fflush(stdin);
    while (!(car=='>' || car=='<')){
        printf(">> Error, donem un caracter > o < \n");
        scanf("%c",&car);
        fflush(stdin);
    }
    printf(">> Caracter: %c", car);
    printf("\n>> Ara donem un primer nombre: ");
    scanf("%d",&num1);
    printf(">> Y ara un segon nombre: ");
    scanf("%d",&num2);
    printf("\n>> Primer nombre: %d Segon nombre: %d\n",num1,num2);

    if (num1>num2){
        aux=num1;
        num1=num2;
        num2=aux;
    }

    if (car=='>'){
        for (;num1<=num2; num1++){
            printf("%d\t",num1);
            }
        }
        for (;num2>=num1; num2-=1){
            printf("%d\t",num2);
    }
    return 0;
}


// Caràcter: ‘>’
// Primer número: 10     Segon Número: 2
// Resultat: 2 3 4 5 6 7 8 9 10
// Caràcter: ‘>’
// Primer número: 2      Segon Número: 10
// Resultat: 2 3 4 5 6 7 8 9 10
// Caràcter: ‘<’
// Primer número: 10     Segon Número: 2
// Resultat: 10 9 8 7 6 5 4 3 2
// Caràcter: ‘<’
// Primer número: 2      Segon Número: 10
// Resultat: 10 9 8 7 6 5 4 3 2
