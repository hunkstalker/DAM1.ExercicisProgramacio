/* Dossier UF1, Tema 2.3 Exercici 19.

(Fibonacci)
Fer un algoritme que calculi el terme n de la s�rie de Fibonacci. Aquesta s�rie est� composada de la seg�ent manera:
*/

#include <stdio.h>
#include <stdlib.h>

int n, cont, f2a, fa, f = 0;

int main () {
	printf("Introdueix quin terme vols: ");
	scanf("%d",&n);
	
	cont=2;
	f2a=0;
	fa=1;
	
	while (cont<n) {
		f=f2a+fa;
		f2a=fa;
		fa=f;
		cont++;
	}
	return 0;
}

/* F1 = 0;
F2 = 1;
Fn = Fn-1 + Fn-2;
Aquesta s_erie _es: 0,1,1,2,3,5,8,13,21,34,55.....

Exemple:
N�mero: 6
Resultat: 5 
*/
