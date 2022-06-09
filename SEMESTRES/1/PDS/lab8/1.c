#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void mean(double v[], int N, int *close) {
    double sum = 0;

    for(int i = 0; i < N; i++)
        sum += v[i];

    double average = sum / N;

    double dif = 99999999;

    for(int i = 0; i < N; i++) {
        double crr_dif = fabs(v[i]-average);

        if(crr_dif < dif) {
            *close = i;
            dif = crr_dif;
        }
    }
}

int main() {
    int N;

    scanf("%d", &N);

    double v[N];

    for(int i = 0; i < N; i++)
        scanf("%lf", &v[i]);
    
    int close = 0;

    mean(v, N, &close);

    printf("%d\n", close);
}