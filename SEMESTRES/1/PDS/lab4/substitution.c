#include <stdio.h>
#include <string.h>

int main() {
    char str[1100], curr, sub;

    fgets(str, sizeof str, stdin);

    scanf("%c", &curr);
    setbuf(stdin,NULL);
    scanf("%c", &sub);

    for(int i = 0; i < strlen(str)-1; i++) {
        if(str[i] == curr) {
            str[i] = sub;
            break;
        }
    }

    printf("%s\n", str);

    return 0;
}