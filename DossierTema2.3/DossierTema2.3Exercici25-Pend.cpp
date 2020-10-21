/* Dossier UF1, Tema 2.3 Exercici 25.

(Compta_Paraules)
Donada una frase acabada en '.'. Calcula quantes paraules s'han introduït.
Cal tenir en compte que els caràcters que introduirem seran tots correctes i que entre paraula i 
paraula hi poden haver més d'un espai. Recordeu el l'espai en blanc equival al codi ascii 10
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cont=0;
char car[1], carAnt[1];

int main () {
	printf("Introdueix un caracter: ");
	fgets(carAnt,2,stdin);
	fflush(stdin);
	
	if (carAnt[0]=='.'){
		printf("DEP");
	} else if (carAnt[0]!=' '){
		cont++;
	}
	printf("Introdueix un caracter: ");
	fgets(car,2,stdin);
	fflush(stdin);
	while (car[0]!=' '){
		if (car[0]!=' ' && carAnt[0]==' '){
			cont++;
		}
		carAnt[0]=car[0];
		printf("Introdueix un caracter: ");
		fgets(car,2,stdin);
		fflush(stdin);
	}
	printf("Hem trobat %d", cont, "paraules.");
	return 0;
}

/*
Exemple;
Caracters introduïts per l'usuari:    
Hola  adeu a.
Resultat: Total de paraules: 3
*/
