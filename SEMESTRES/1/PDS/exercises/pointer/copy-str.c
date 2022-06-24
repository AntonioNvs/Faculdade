/*
    - Crie uma função que receba uma string como parâmetro (de
    tamanhodesconhecido) e retorne uma cópia da mesma. A assinatura da
    função deveser:char *strcopy(char *str);
*/

#include <stdio.h>
#include <stdlib.h>

char *strcopy(char *str) {
    char *copy;

    copy = (char *)malloc(sizeof(char)*sizeof(str));

    int i;
    for(i = 0; str[i] != '\0'; i++) {
        copy[i] = str[i];
    }

    copy[i] = '\0';

    return copy;
}

int main() {
    char name[8] = "Antônio";

    printf("%s\n", strcopy(name));

    return 0;
}