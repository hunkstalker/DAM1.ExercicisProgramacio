/* Dossier UF1, Tema 2.3 Exercici 20.

(Comptar "la"s) Fer un algoritme que donat una sèrie de caràcters introduïts per l'usuari, calculi en nombre de "la" introduïdes.
Finalitzarem d'introduir caracters quan l'usuari posi un '.'
*/

#include <stdio.h>
#include <stdlib.h>

int contLA=0;
char carAnt='L';
char car='A';

int main () {
	printf("Introdueix un caracter: ");
	scanf("%s",&car);
	
	if (car=='.'){
		printf("Gamarus has acabat abans de comencar.");
	} else {
		carAnt=car;
		while (car!='.'){
			if ((car=='l' || car=='L') && (carAnt=='a' || carAnt=='A')){
				contLA++;
			}
			carAnt=car;
			printf("Introdueix un caracter: ");
			scanf("%s",&car);
		}
		printf("%s%d%s",("L'usuari a introduit "), contLA, (" cops la sequencia 'la'."));
	}
}


/* Exemple:.
Usuari introdueix: LArrLalartla.
Resposta: L'usuari a introduit 4 cops la sequencia 'la'
*/
