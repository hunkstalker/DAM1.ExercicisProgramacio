/* Dossier UF1. Tema 2.3 Exercici 11 

(MesGranMesPetit)
Calcula el numero m�s gran i m�s petit dels n�meros introdu�ts per teclats.
Acabem d'introduir n�meros quan l'usuari ens introdueixi el 0. EL 0 no s'ha de tenir en compte, 
�s una marca final.
*/

#include <iostream>
#include <stdio.h>

int main() {
	int num, max, min=0;
	printf("Introdueix un nombre.\n");
	scanf("%d", &num);
	min=num, max=num;
	while (num!=0){
		if (num>max){
			max = num;
		}
		else if (num<min){
			min = num;
		}
		printf("Introdueix un altre nombre o escull 0 per sortir.\n");
		scanf("%d", &num);
	}
	printf("%s%d\n", ("El nombre maxim escollit es :"), max);
	printf("%s%d\n", ("El nombre minim escollit es :"), min);
	return 0;
}
