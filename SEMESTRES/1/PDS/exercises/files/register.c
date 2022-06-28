/*

    Em um sistema de inserção e leitura de arquivo de textos,
    com um número de operações, guarde ou leia sempre um vetor
    de 10 elementos

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

int ** read() {
    FILE *file = fopen("register.txt", "r");
    
    int **vectors = (int **) malloc(sizeof(int*)*MAX);

    int count = 1;
    int idx = 0;
    vectors[0] = (int *) malloc(sizeof(int));
    vectors[count] = (int *) malloc(sizeof(int)*MAX);

    while(fscanf(file, "%d", &vectors[count][idx]) != EOF) {
        idx++;

        if(idx == MAX) {
            idx = 0;
            count++;
            vectors[count] = (int *) malloc(sizeof(int)*MAX);
        }
    }
    vectors[0][0] = count-1;

    fclose(file);

    return vectors;
}

void write(int v[]) {
    int **vectors = read();

    FILE *file = fopen("register.txt", "a");


    if(vectors[0][0] != 0)
        fprintf(file, "\n");

    for(int i = 0; i < MAX; i++)
        fprintf(file, "%d ", *(v+i));

    fclose(file);
}

int main() {
    int T;
    scanf("%d", &T);

    while(T--) {
        char action[10];
        scanf("%s", action);

        if(!strcmp(action, "Ler")) {
            int **vectors = read();
            int N = vectors[0][0];
            
            for(int i = 1; i <= N; i++) {
                for(int j = 0; j < MAX; j++)
                    printf("%d ", vectors[i][j]);
                printf("\n");
            }
        } else if(!strcmp(action, "Escrever")) {
            int *v = (int *) malloc(sizeof(int)*MAX);
            for(int i = 0; i < MAX; i++)
                scanf("%d", &v[i]);
            write(v);
        }
    }
}