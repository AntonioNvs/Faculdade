/*

    Em um sistema de inserção e leitura de arquivo de textos,
    com um número de operações, guarde ou leia sempre um vetor
    de 10 elementos

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void write(int v[], int N) {
    FILE *file = fopen("register.txt", "w");

    for(int i = 0; i < N; i++)
        fprintf(file, "%d ", v+i);
    fprintf(file, "\n");
}

int ** read() {
    FILE *file = fopen("register.txt", "r");
    
    int **vectors = (int **) malloc(sizeof(int*)*MAX);

    int count = 1;
    int idx = 0;

    vectors[1] = (int *) malloc(sizeof(int)*10);

    while(!feof(file)) {
        
        fscanf(file, "%d", &vectors[count][idx]);
        idx++;

        if(idx == 10) {
            idx = 0;
            count++;
            vectors[count] = (int *) malloc(sizeof(int)*10);
        }
    }
    vectors[0][0] = count;

    vectors = (int **) realloc(vectors, count);

    return vectors;
}

int main() {
    int T;
    scanf("%d", &T);

    while(T--) {
        char action[100];
        scanf("%s", action);

        if(!strcmp(action, "Ler")) {
            int **vectors = read();
            int N = vectors[0][0];

            for(int i = 1; i < N; i++) {
                for(int j = 0; j < 10; j++)
                    printf("%d ", vectors[i][j]);
                printf("\n");
            }
        } else if(!strcmp(action, "Escrever")) {
            
        }
    }
}