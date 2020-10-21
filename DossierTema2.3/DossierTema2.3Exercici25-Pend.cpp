/* Dossier UF1, Tema 2.3 Exercici 25.

(Compta_Paraules)
Donada una frase acabada en '.'. Calcula quantes paraules s'han introdu�t.
Cal tenir en compte que els car�cters que introduirem seran tots correctes i que entre paraula i 
paraula hi poden haver m�s d'un espai. Recordeu el l'espai en blanc equival al codi ascii 10
*/

#include <stdio.h>
#include <stdlib.h>

int cont=0;
char car[1], carAnt[1];

int main () {
	printf("Introdueix un caracter: ");
	fgets(carAnt,2,stdin);
	
	if (carAnt[1]=='.'){
		printf("DEP");
	} else if (carAnt[1]!=' '){
		cont++;
	}
	printf("Introdueix un caracter: ");
	fgets(car,2,stdin);
	while (car[1]!=' '){
		if (car[1]!=' ' && carAnt[1]==' '){
			cont++;
		}
		carAnt[1]=car[1];
		printf("Introdueix un caracter: ");
		fgets(car,2,stdin);
	}
	printf("Hem trobat %d", cont, "paraules.");
	return 0;
}

/*
Exemple;
Caracters introdu�ts per l'usuari:    
Hola  adeu a.
Resultat: Total de paraules: 3
*/
