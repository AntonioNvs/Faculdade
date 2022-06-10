#include <stdio.h>
#include <string.h>

int main() {
    char str[1011], other[1100];

    fgets(str, sizeof str, stdin);

    str[strlen(str)-1] = '\0';

    for(int i = strlen(str)-1; i >= 0; i--) {
        other[i] = str[strlen(str)-1-i];
    }

    printf("%s\n", other);
}