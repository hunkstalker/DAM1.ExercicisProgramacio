#include <stdio.h>
#include <stdlib.h>

int aux=0, num1=0, num2=0;

int intercanviVariables(num1,num2){
    aux=a;
    a=b;
    b=aux;
}

int main()
{
    printf(">> Escull els valor que vols intercanvar.\n");
    printf(">> # 1: ");
    scanf("%d",&num1);
    printf(">> # 2: ");
    scanf("%d",&num2);

    intercanviVariables(num1, num2);
    printf(">> Ara el valor #1 es %d y el valor #2 es %d.\n",num1,num2);
    return 0;
}
