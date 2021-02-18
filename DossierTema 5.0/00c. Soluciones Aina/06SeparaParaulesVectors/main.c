#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXCADENA 30
#define FICADENA '\0'

bool esLletra(char caracter);

int main()
{

    char frase[MAXCADENA]=" Who rule   the  world  ";

    copiaParaulesVector(frase,MAXCADENA);


    return 0;
}


///Copia les paraules que trobis al vector original a un altre vector

void copiaParaulesVector(char frase[],int qttC){

    int i=0,qttParaules=0;

    char copia[MAXCADENA];

    while(frase[i]!=FICADENA && i<qttC){

        passaNoLletres(frase,&i,qttC);

        //Nom�s entrar� en cas que frase[i] sigui una lletra, si el vector est� buit no sumar� res

        if(esLletra(frase[i])){

            copiaLletresVector(frase,copia,&i,qttC);
            qttParaules++;

            if(qttParaules>0)printf("\n");

            pintaCadena(copia,MAXCADENA);


        }
    }

}



///Funci� que col�loca posici� passat els valors que no s�n lletres

void passaNoLletres(char frase[],int *i,int qttMax){

    while(!esLletra(frase[*i]) && *i<qttMax && frase[*i]!=FICADENA){(*i)++;}
}

///Copia les paraules al vector COPIA
void copiaLletresVector(char frase[],char copia[],int *posicio,int qttMax){

    int i=0;

    while(esLletra(frase[*posicio]) && *posicio<qttMax && frase[*posicio]!=FICADENA){

        copia[i]=frase[*posicio];
        (*posicio)++;
        i++;
    }

    copia[i]=FICADENA;

}

///Pinta una cadena amb printf

void pintaCadena(char cadena[],int qttMax){

    int i=0;

    while(i<qttMax && cadena[i]!=FICADENA){

        printf("%c",cadena[i]);
        i++;
    }

    //printf("\n");

}

///Controla si el car�cter passat �s lletra o no
bool esLletra(char caracter){
    char lletres[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ������������abcdefghijklmnopqrstuvwxyz������������";
    bool lletra=false;
    int i=0;

        while (lletres[i]!=FICADENA && !lletra)
    {
        if (lletres[i]==caracter) lletra=true;
        else i++;
    }

    return lletra;
}
