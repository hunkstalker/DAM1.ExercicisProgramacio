/* Dossier UF1, Tema 2.3 Exercici 16.

(Comptar 'a's limitat)
Fer un algoritme que demani un número natural entre 5 i 10 a l'usuari. 
L'algoritme ha de demanar desprès tantes lletres com indiqui el número demanat anteriorment i en finalitzar, 
ha de mostrar per pantalla quantes lletres 'a' ha introduït l'usuari.
*/

#include <iostream>
#include <stdio.h>

int cont, numUser=0;
char car='z';

int main (){
	printf("Introdueix un nombre entre 5 i 10.\n");
	scanf("%d",&numUser);
	while (numUser<5 || numUser>10){
		printf("Error(!). Se't demana un nombre entre 5 i 10. Torna a provar, hop hop!\n");
		scanf("%d",&numUser);
	}
	if (numUser>=5 && numUser<=10){
		for (int i=0; i<numUser; i++){
			printf("%s\n",("Ara donem lletres"));
			scanf("%s", &car);
			if (car=='a'){
				cont++;
			}
		}
		printf("%s%d%s\n",("L'usuari ha introduit "), cont, (" cop/s el caracter 'a'."));
	}
	return 0;
}

/* Exemple:
Numero: 6   //cal controlar que el numero estigui entre 5 i 10
Usuari introdueix: edtsfa
Resposta: L'usuari ha introduit 1 cop el caracter 'a'
*/
