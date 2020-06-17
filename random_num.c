#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int i,n;

    time_t t;

    n = 25;

    srand((unsigned)time(&t));

    for (i = 0; i < n; i++){
        printf("%d ",1000+rand() % 5000);

    }

    return 0;
}