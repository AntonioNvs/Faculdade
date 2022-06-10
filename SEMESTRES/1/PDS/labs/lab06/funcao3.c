#include <stdio.h>

int primo(long long int n) {
    long long int i;
    for(i = 2; i*i <= n; i++)
        if(n % i == 0)
            return 0;
    return 1;
}

int main() {
    int n;

    while(scanf("%d", &n) != EOF) {
        long long int c = 0, p = 2, s = 0;

        while(c < n) {
            if(primo(p)) {
                s += p;
                c++;
            }
            p++;
        }

        printf("%d\n", s);
    }
    
    return 0;
}
