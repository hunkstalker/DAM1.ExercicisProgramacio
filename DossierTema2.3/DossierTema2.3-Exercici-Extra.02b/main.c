#include <stdio.h>
#include <stdlib.h>

/* Exercici Extra 2b

LA MATRÍCULA DER DIABOLO.B
*/


int main()
{
    int M=0, C=0, D=0, U=0;
    int i=0;

    if (i<=9999){
        while (M<=9){
                C=0;
            while (C<=9){
                U=M*C;
                printf("%d%d%d%d0\n",M,C,D,U);
                C++;
            }
            M++;
        }
    }
    return 0;
}
