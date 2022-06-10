#include <stdio.h>
#include <string.h>

#define MAX 110

int main() {
    char str[MAX], sub[MAX];

    fgets(str, sizeof str, stdin);
    fgets(sub, sizeof sub, stdin);
    
    for(int i = 0; i < strlen(str)-1; i++) {
        int igual = 1;
        int j;
        
        for(j = 0; j < strlen(sub)-1; j++) {
            if(str[i+j] != sub[j]) {
                igual = 0;
                break;
            }
        }

        if(igual) {
            printf("É substring de %d até %d\n", i, i+j-1);
            return 0;
        }
    }

    printf("Não é substring\n");

    return 0;
}