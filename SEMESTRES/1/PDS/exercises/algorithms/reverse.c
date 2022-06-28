#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int reverse(int n, int qtd_dig) {
    if(n < 10)
        return n;
    
    return (n % 10) * pow(10, qtd_dig) + reverse(n/10, qtd_dig-1);
}

int main() {
    int N;
    scanf("%d", &N);

    int dig = 0;
    int cN = N;

    while(cN > 0) {
        dig++;
        cN /= 10;
    }

    printf("%d\n", reverse(N, dig-1));
    return 0;
}