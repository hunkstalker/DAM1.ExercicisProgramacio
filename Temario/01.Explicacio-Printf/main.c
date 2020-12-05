#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int a=5, c=2;
    float b=3.5;
    char car='g';
    bool trobat=false;

    printf("El valor de a es: %i", a);
    printf("\n%i residu %i = %i",a,c,a%c);
    printf("\nDivisio: %i/%i=%i",a,c,a/c);
    printf("\n%i/%i=%.2f",a,c,(float)a/c);
    printf("\n%i/%i=%.2f",a,c,1.0*a/c); // alternativa
    printf("\ncar:%c car:%i",car,car);
    printf("\ntrobat:%d", trobat);

    return 0;
}
