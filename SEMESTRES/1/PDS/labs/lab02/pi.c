#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double precision;
    double pi = 4.0, sinal = -1.0, div = 3.0;

    int i = 1;
    
    scanf("%lf", &precision);

    while(fabs(pi-M_PI) > precision) {
        pi += sinal*4/div;
        sinal *= -1.0;
        div = div + 2.0;
        i++;
    }
    
    printf("%d\n", i);

    return 0;
}