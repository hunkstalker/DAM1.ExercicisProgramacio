#include <stdio.h>
#include <stdlib.h>

/* Dossier UF1. Tema 2.2, Exercici 11

(Convertidor_Temperatures)
Realitza un programa que demani la temperatura en graus Celsius
i la converteixi en graus Fahrenheit (i viceversa) mostrant per pantalla un missatge del tipus:
*/

int main()
{
    float temp=0;
    int graus=0;

    printf(">> Quina conversio vols fer?\n>> 1: de graus Celsius a Fahrenheit.\n>> 2: de graus Fahrenheit a Celsius.\n>> ");
    scanf("%d",&graus);
    printf(">> Introdueix una temperatura: \n>> ");
    scanf("%f",&temp);
    while (temp<-273.15){
        printf(">> Valor incorrecte per sota del cero absolut.\n>>Torna a introuir una temperatura: \n>> ");
        scanf("%f",&temp);
    }
    switch (graus){
        case 1: printf("\n-- %.2f graus Celsius son %.2f graus Fahrenheit.\n", temp, ((temp*9/5)+32));
            break;
        case 2: printf("\n-- %.2f graus Fahrenheit son %.2f graus Celsius.\n", temp, ((temp-32)*5/9));
            break;
        }
    return 0;
}

// La formula per a convertir graus Celsius a Fahrenheit és la següent: (F-32)/9=c-5

// Per a fer la resolució de l’exercici, és demanarà a l’usuari quina de les dues conversions vol fer:
// 1: de graus Celsius a Fahrenheit
// 2: de graus Fahrenheit a Celsius
// l’usuari introduirà un 1 si vol fer la conversió de graus Celsius a Fahrenheit (i per tant introduirà la quantitat de graus Celsius que vol convertir a Fahrenheit) i 2 en cas que vulgui realitzar la conversió de graus Fahrenheit a Celsius
// (i per tant introduirà els graus Fahrenheit que vol convertir a Celsius).
// Per exemple: usuari introdueix 1 i 25 graus Celsius
// Resultat: 25 graus Celsius son 77 graus Fahrenheit
// Per exemple: usuari introdueix 2 i 56 graus Fahrenheit
// Resultat: 56 graus Fahrenheit son 13.33 graus Celsius
