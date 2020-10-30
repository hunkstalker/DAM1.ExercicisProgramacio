#include <stdio.h>
#include <stdlib.h>

/* Exercici Extra 2a

LA MATRÍCULA DER DIABOLO.A
*/

int main()
{
    int M=0, C=0, DU=0;

    while (M<=9){
        C=0;
        while (C<=9){
            DU=M*C;
            printf("%d%d%02d\t", M, C, DU);
            C++;
        }
        printf("\n");
        M++;
    }
    return 0;
}
