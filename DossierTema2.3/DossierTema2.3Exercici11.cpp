#include <iostream>
#include <stdio.h>

// Dossier UF1. Tema 2.3 ITERACIONS.

int num, max, min=0;

int main() {

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
