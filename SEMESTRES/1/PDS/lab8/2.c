#include <stdio.h>
#include <stdlib.h>

int prime(int n) {
    if(n < 2)
        return 0;

    for(int i = 2; i*i <= n; i++)
        if(n%i == 0)
            return 0;
    return 1;
}

void get(int m, int *p1, int *p2) {
    for(int i = m-1; i >= 2; i--)
        if(prime(i)) {
            *p1 = i;
            break;
        }
    
    while(m++)
        if(prime(m)) {
            *p2 = m;
            break;
        }
}

int main() {
    int N;

    scanf("%d", &N);

    int p1, p2;

    get(N, &p1, &p2);

    printf("%d\n%d\n", p1, p2);
}