#include <stdio.h>

void inverseNumber(int n) {
    if(n == 0) {
        printf("\n");
        return;
    }

    printf("%d", n % 10);

    inverseNumber((int)(n / 10));
}

int main() {
    int n;

    scanf("%d", &n);

    inverseNumber(n);
    
    return 0;
}