/* Dossier UF1, Tema 2.3 Exercici 15.

(Comptar 'a' s)
Fer un algoritme que donat una s�rie de car�cters introdu�ts per l'usuari, 
calculi el nombre de lletres 'a' introdu�des. L'usuari introduir� 10 car�cters.
*/

#include <iostream>
#include <stdio.h>

char car='z';
int i, cont=0;

int main(){
	for (i=1; i<=3; i++){
		printf("%s",("Introdueix un altre lletra.\n"));
		scanf("%s",&car);
		if (car=='a'){
			cont++;
		}
	} 
	printf("%s%d%s",("L'usuari ha introduit "), cont, (" cops el caracter 'a'.\n"));
	return 0;
}

/* Exemple:
Usuari introdueix: arcftadrfq
Resposta: L'usuari ha introduit 2 cops el caracter 'a'
*/
