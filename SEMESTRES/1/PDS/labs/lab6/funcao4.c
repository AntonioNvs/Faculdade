#include <stdio.h>

int bissexto(int y) {
    return y % 4 == 0 && (y % 100 != 0 || y % 400 == 0);
}

int main() {
    int y;

    while(scanf("%d", &y) != EOF) {
        printf("%d\n", bissexto(y));
    }
    
    return 0;
}
