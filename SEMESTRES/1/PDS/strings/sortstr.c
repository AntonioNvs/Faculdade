#include <stdio.h>
#include <string.h>

#define MAX 110

int main() {
    char str[MAX];

    fgets(str, sizeof str, stdin);
    
    for(int i = 0; i < strlen(str)-1; i++) {
        for(int j = i+1; j < strlen(str)-1; j++) {
            if(str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }

    printf("%s", str);

    return 0;
}