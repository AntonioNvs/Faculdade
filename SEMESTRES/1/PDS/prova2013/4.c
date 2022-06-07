#include <stdio.h>
#include <math.h>

int inverse(int n, int num, int pot) {
    if(n == 0) {
        return num;
    }

    num += (n % 10) * (int)pow((double)10, (double)pot);

    return inverse((int)(n/10), num, pot-1);
}

int main() {
    int n, cpy;

    scanf("%d", &n);
    
    int pot = 0;
    cpy = n;

    while(n != 0) {
        n = (int)(n/10);
        pot++;
    }

    int inver = inverse(cpy, 0, pot-1);

    printf("%d\n", inver);

    return 0;
}