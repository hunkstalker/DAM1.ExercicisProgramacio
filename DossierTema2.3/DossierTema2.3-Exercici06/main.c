#include <stdio.h>
#include <stdlib.h>

/* Dossier UF1. Tema 2.3 Exercici 6

6.(><)
Fer un algoritme que demani a l'usuari dos nombres naturals i un car�cter,
que pot ser �>� o �<�. Llavors, l'algoritme ha de mostrar per pantalla tots els
nombres naturals entre els dos introdu�ts, ordenats de menor a major si el car�cter
�s �>� o de major a menor si el car�cter �s �<�
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


// Car�cter: �>�
// Primer n�mero: 10     Segon N�mero: 2
// Resultat: 2 3 4 5 6 7 8 9 10
// Car�cter: �>�
// Primer n�mero: 2      Segon N�mero: 10
// Resultat: 2 3 4 5 6 7 8 9 10
// Car�cter: �<�
// Primer n�mero: 10     Segon N�mero: 2
// Resultat: 10 9 8 7 6 5 4 3 2
// Car�cter: �<�
// Primer n�mero: 2      Segon N�mero: 10
// Resultat: 10 9 8 7 6 5 4 3 2
