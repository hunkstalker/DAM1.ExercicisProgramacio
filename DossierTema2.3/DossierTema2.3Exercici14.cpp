/* Dossier UF1, Tema 2.3 Exercici 14.

(Lletres)
Fer un algoritme que conti quantes lletres ha introduït l'usuari fins que introdueixi una 'z' o 'Z'.
*/

#include <iostream>
#include <stdio.h>

int cont=0;
char car='a';

int main () {
	
	printf("Dame una letra\n");
	scanf("%s", &car);
	while (!(car=='z' || car=='Z')){
		cont++;
		printf("Dame una letra\n");
		scanf("%s", &car);
	}
	printf("%s%i%s\n", ("L'usuari ha introduit "), cont, (" lletres."));
	return 0;
}

/* Exemple:
Usuari introdueix: afgw34.8rz
Resposta: L'usuari ha introduit 9 lletres
*/
