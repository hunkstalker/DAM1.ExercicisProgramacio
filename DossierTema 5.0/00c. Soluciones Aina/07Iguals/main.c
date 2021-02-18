#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXCADENA 10
#define FICADENA '\0'

bool comparaDuesCadenes(char cadena1[],char cadena2[],int qttMax);

int main()
{
    char cadena1[MAXCADENA]="Hola";
    char cadena2[MAXCADENA]="Hola";
    bool iguals=true;

    printf("%s",cadena1);
    printf("\n%s",cadena2);

    iguals=comparaDuesCadenes(cadena1,cadena2,MAXCADENA);

    if(!iguals)printf("\nLes cadenes son diferents.");
    else printf("\nLes cadenes son iguals.");

    return 0;
}

bool comparaDuesCadenes(char cadena1[],char cadena2[],int qttMax){

    int i=0,j=0;
    bool trobat=true;

    while(i<qttMax && trobat==true && (cadena1[i]!=FICADENA || cadena2[j]!=FICADENA) ){

        if(cadena1[i]!=cadena2[i])trobat=false;
        else i++;

    }


    return trobat;
}
