#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int x, y, z;

    scanf("%i", &x);
    scanf("%i", &y);
    scanf("%i", &z);

    if(x % y == 0 && x % z == 0) {
        printf("O número é divisível");
    } else {
        printf("O número não é divisível");
    }

    return 0;
}

