#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXCADENA 30
#define FICADENA '\0'

bool esLletra(char caracter);

///Conta paraules amb el mètode de dins/fora (variable d'estat)

int main()
{

    char frase[MAXCADENA]={"  Bon dia   Eduard  "};

    printf("\nLa cadena te %d paraules.",comptaParaulesDins(frase,MAXCADENA));

    return 0;
}


///Compta les paraules amb el mètode de dins/fora

int comptaParaulesDins(char frase[],int qttMax){

    int i=0,qttParaules=0;
    bool dins=false;

    while(i<qttMax && frase[i]!=FICADENA){

        //Incremento el qttPraules quan passem de false a true en el flanc de pujada, no de true a false
        if(esLletra(frase[i]) && dins==false){
                qttParaules++;
                dins=true;}
        else if(!esLletra(frase[i]) && dins==true){dins=false;}
        i++;
    }

    return qttParaules;
}


///Controla si el caràcter passat és lletra o no
bool esLletra(char caracter){
    char lletres[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZÀÁÈÉÍÏÒÓÚÜÑÇabcdefghijklmnopqrstuvwxyzàáèéíïòóúüñç";
    bool lletra=false;
    int i=0;

        while (lletres[i]!=FICADENA && !lletra)
    {
        if (lletres[i]==caracter) lletra=true;
        else i++;
    }

    return lletra;
}
