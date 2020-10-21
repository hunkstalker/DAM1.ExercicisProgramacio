/* Dossier UF1, Tema 2.3 Exercici 20.

(Comptar "la"s) Fer un algoritme que donat una sèrie de caràcters introduïts per l'usuari, calculi en nombre de "la" introduïdes.
Finalitzarem d'introduir caracters quan l'usuari posi un '.'
*/

#include <stdio.h>
#include <stdlib.h>

int cont=0;
char car1='L';
char car2='A';

int main () {
	while (car1!='.'){
		printf("Introdueix un caracter: ");
		scanf("%s",&car1);
		if (car1=='l' || car1=='L'){
			printf("Introdueix un caracter: ");
			scanf("%s",&car2);
			if ((car1=='l' || car1=='L') && (car2=='a' || car2=='A')){
			cont++;
			} 
		}
	}
	printf("%s%d%s",("L'usuari a introduit "), cont, (" cops la sequencia 'la'."));
}


/* Exemple:.
Usuari introdueix: LArrLalartla.
Resposta: L'usuari a introduit 4 cops la sequencia 'la'
*/
