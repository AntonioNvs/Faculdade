#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int N;

    scanf("%i", &N);

    printf("100: %i\n", N / 100);
    N = N >= 100 ? N - 100*(N / 100): N;

    printf("50: %i\n", N / 50);
    N = N >= 50 ? N - 50*(N / 50): N;

    printf("20: %i\n", N / 20);
    N = N >= 20 ? N - 20*(N / 20): N;

    printf("10: %i\n", N / 10);
    N = N >= 10 ? N - 10*(N / 10): N;

    printf("5: %i\n", N / 5);
    N = N >= 5 ? N - 5*(N / 5): N;

    printf("2: %i\n", N / 2);
    N = N >= 2 ? N - 2*(N / 2): N;

    printf("1: %i\n", N / 1);
    N = N >= 1 ? N - 1*(N / 1): N;



    return 0;
}
