#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int a, b,c;

    scanf("%i", &a);
    scanf("%i", &b);
    scanf("%i", &c);

    if(a > b && a > c)
        printf("%i\n", a);
    else if(b > a && b > c)
        printf("%i\n", b);
    else if(c > a && c > a)
        printf("%i\n", c);
    else if(a == b || b == c)
        printf("%i\n", b);

    return 0;
}
