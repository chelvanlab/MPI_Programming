#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main(){

    int gen_rendom[6];
    int multi_random[6];

    time_t t;
    srand((unsigned)time(&t));

    // generate 6 random numbers
    for (int i = 0; i < 6; i++){
        gen_rendom[i] = 1000+rand() % 5000;

    }

    printf("%d ",gen_rendom);

}