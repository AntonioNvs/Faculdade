/*

Escreva uma função que recebe uma string de caracteres e uma letra e devolve
 um vetor de inteiros contendo as posições (índices no vetor dastring) onde a 
letra foi encontrada) e um inteiro contendo o tamanho do vetor criado
(total de letras iguais encontradas). Utilize o retorno de um vetor para 
retornar os índices e um ponteiro para guardar o tamanho do vetor.

*/

#include <stdio.h>
#include <stdlib.h>


int ** count(char *str, char letter) {
    int count;
    int *indexs = (int *) malloc(sizeof(int)*sizeof(str));

    for(int i = 0; str[i] != '\0'; i++)
        if(str[i] == letter)
            indexs[count++] = i;

    indexs = realloc(indexs, count*sizeof(int));

    int **result = (int **) malloc(sizeof(int)*2);

    result[0] = indexs;
    result[1] = &count;

    return result;
}

int main() {
    char name[] = "Olá tudo bem, eu sou Antônio";

    int **result = count(name, 'o');

    printf("Indexs: ");
    for(int i = 0; i < *(result[1]); i++) {
        printf("%d ", result[0][i]);
    }

    printf("\nCount: %d\n", *(result[1]));
}