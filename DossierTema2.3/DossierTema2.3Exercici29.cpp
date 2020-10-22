/* Dossier UF1, Tema 2.3 Exercici 29.

(Mastermind)
Fer un algoritme que generi un nombre aleatori de 4 xifres.
L'usuari llavors ha d'introduir nombres de 4 xifres fins que l'encerti o be hagi fet n intents.
El nombre d'intents també els ha d'introduir l'usuari. A cada nombre de 4 xifres que introdueixi l'usuari, 
el programa li ha de dir si el nombre que ha d'endevinar és més gran o més petit. Si l'usuari l'encerta en un 
nombre de vegades menor que n, llavors ha guanyat. Si no, ha perdut.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int attempts;
int numRnd=0;
int num1, num2, num3, num4=0;
int m, c, d, u;

int main (){
	
	
	srand(time(NULL));
	int numRnd = rand()%10000;
	printf("Avis: el nombre 'secret' aleatori es %d\n", numRnd);
	
	/*printf("Quants intents vols fer?");
	fgets(attempts,2,stdin);
	fflush(stdin);
	printf("Registrat: el nombre de intents restants es %d\n\n", attempts);
	
	printf("Ara introdueix un caracter: \n");
	fgets(num1,2,stdin);
	fflush(stdin);
	
	printf("El nombre introduit es el :%d", num1, " y es correcte");*/
	return 0;
}
