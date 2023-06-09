#include <stdio.h>
#include <stdlib.h>
#include <time.h>



float train[][2] = {
    {0, 0},
    {1, 2},
    {2, 4},
    {3, 6},
    {4, 8}
};

#define train_count (sizeof(train) / sizeof(train[0]))

float rand_float(void) {
    return (float)rand() / (float)RAND_MAX;
}


float cost(float w) {

    float res = 0.0f;
    for (int i  = 0; i < train_count; i++) {
        float x = train[i][0];
        float y = x * w;
        float d = y - train[i][1];
        res += d*d;
        // printf("got %f, expected %f\n", y , train[i][1]);
    }

    res /= train_count;
    return res;
     
}

int main() {
    srand(69);

    float w = rand_float() * 10;
     printf("res = %f\n" , cost(w));
    float eps = 1e-3;
    float rate = 1e-3;
    for (int i = 0 ; i < 764; i++){
        float dcost = (cost(w + eps) - cost(w)) / eps;
        w -= rate * dcost;
        printf("res = %f\n" , cost(w));
    }

    printf("---------------------------\n");
    printf("w = %f\n" , w);

    return 0;
}