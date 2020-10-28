#include <stdio.h>
#include <stdlib.h>

/* Dossier UF1. Tema 2.3 Exercici 11

(MesGranMesPetit)
Calcula el numero més gran i més petit dels números introduïts per teclats.
Acabem d'introduir números quan l'usuari ens introdueixi el 0. EL 0 no s'ha de tenir en compte,
és una marca final.
*/

int main()
{
	int num, max, min=0;

	printf(">> Introdueix un nombre: ");
	scanf("%d", &num);
	min=num;
	max=num;

	while (num!=0){
		if (num>max){
			max = num;
		}
		else if (num<min){
			min = num;
		}
		printf(">> Introdueix un altre nombre o escull 0 per sortir.\n");
		printf(">> ");
		scanf("%d", &num);
	}
	printf("%s%d\n", ("-- El nombre maxim escollit es: "), max);
	printf("%s%d\n", ("-- El nombre minim escollit es: "), min);
	return 0;
}

// Exemple:
// Nombres introduits per l’usuari: 1 5 7 4 2 4 5 8 4 6 0
// Resultat: Maxim: 8; Minim: 1
//
// Nombres introduits per l’usuari: 0
// Resultat: No s’ha introduït cap valor correcta
