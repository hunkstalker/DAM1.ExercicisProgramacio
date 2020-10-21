/* Dossier UF1, Tema 2.3 Exercici 23.

(Totes_les_vocals)
Fer un algoritme que demani a l'usuari una sèrie de lletres acabades en '.'.
Llavors l'algoritme ha de mostrar si en aquesta sèrie de lletres hi ha totes les vocals, almenys un cop.
*/

#include <stdio.h>
#include <stdlib.h>

	bool trobatA = false;
	bool trobatE = false;
	bool trobatI = false;
	bool trobatO = false;
	bool trobatU = false;
	bool trobat = false;
	char car='.';

int main(){
	printf("Introdueix caracter: ");
	scanf("%s",&car);
	
	while (car!='.' && !trobat) {
		switch (car){
			case 'a': trobatA=true;
				break;
			case 'e': trobatE=true;
				break;
			case 'i': trobatI=true;
				break;
			case 'o': trobatO=true;
				break;
			case 'u': trobatU=true;
				break;
		}
		if (trobatA && trobatE && trobatI && trobatO && trobatU){
			trobat=true;
		} else {
			printf("Introdueix caracter: ");
			scanf("%s",&car);
		}
	}
	if (trobat) {
		printf("Has posat les 5 vocals, bravo!");
	} else {
		printf("No has posat les 5 vocals.");
	}
}

/* Exemple
Caracters introduïts per l'usuari: afgtyeaaai.
Resultat: No hi ha totes les vocals

Caracters introduïts per l'usuari:afgrioue
Resultat: S'han trobat com a minim un cop cadascuna de les vocals.
*/
