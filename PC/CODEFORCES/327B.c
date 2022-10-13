#include <stdio.h>
#define MAXN 100100

int primo(int n) {
    if(n < 2)
        return 0;

    for(int i = 2; i*i <= n; i++)
        if(n%i == 0)
            return 0;
    return 1;
}

int main() {
    int N;

    scanf("%d", &N);

    int c = 0, p = 1;

    while(c < N) {
        p++;

        if(primo(p)) {
            printf("%d ", p);
            c++;
        }
    }

    return 0;
}