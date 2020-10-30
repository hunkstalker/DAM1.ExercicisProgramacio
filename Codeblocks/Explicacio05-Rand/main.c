#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n,i;
    srand(time(NULL)); ///primera instruccio

    for (i=0;i>100;i++){
        n=rand();
        printf("%d\t",n);
    }
    return 0;
}
