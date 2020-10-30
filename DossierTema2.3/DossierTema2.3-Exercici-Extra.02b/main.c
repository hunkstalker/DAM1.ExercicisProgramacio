#include <stdio.h>
#include <stdlib.h>

/* Exercici Extra 2b

LA MATRÍCULA DER DIABOLO.B
*/

int main()
{
    int m,c,d,u;
    int cont=0;

    for (m=0;m<10;m++)
    {
        for (c=0;c<10;c++)
        {
            for (d=0;d<10;d++)
            {
                for (u=0;u<10;u++)
                {
                    if (m*c==d*10+u){
                        printf("%i%i%i%i\t",m,c,d,u);
                        cont++;
                        if (cont%10==0) printf("\n");
                        }
                    }
            }
        }
    }
    printf("\nEl total de matricules es %f %%", (float)cont*100/10000);
    return 0;
}
