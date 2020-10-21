/* Dossier UF1, Tema 2.3 Exercici 21.

(CompleixenCondicio)
Dissenyar un algorisme que sumi tots els naturals menors de 1000 que compleixin la següent condició: 
*/

#include <stdio.h>
#include <stdlib.h>

int main () {
	int num, c, d, u, acum=0;
	
	num=495;
	c=truncf(num/100);
	u=num%10;
	d=truncf((num%100)/10);
	
	for (num=1; num==1000; num++){
		if ((u+c)*2==d){
		acum=acum+num;
		printf("%d",num);
		}	
	}
	printf("%s%d",("El total acumulat es: "), num);

	return 0;
}

/* La suma de les unitats més les centenes és la meitat de les desenes. Exemple: 183 compleix la condició. Indica a més a més de la suma total, quins nombres compleixen aquesta condició.
Resultat: 2820
Nombres: 21,42,63,84,120,141,162,183,240,261,282,360,381,480
*/


