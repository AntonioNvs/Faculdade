/*
    Crie um programa que multiplica duas matrizes NxN instanciadas
    aleatoriamente e o tamanho delas dado por linha de comando 
    usando alocação dinâmica e imprimindo o resultado.

    1 <= N <= 9
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int ** create_matrix(int N) {
    int **matrix;

    matrix = (int **) malloc(N*sizeof(int *));

    for(int i = 0; i < N; i++) {
        matrix[i] = (int *) malloc(N*sizeof(int));
        for(int j = 0; j < N; j++)
            matrix[i][j] = rand() % 10;
    }

    return matrix;
}

int ** multiply_matrix(int **m1, int **m2, int N) {
    if(m1 == NULL || m2 == NULL) {
        return NULL;
    }

    int **result;
    result = (int **) calloc(N, sizeof(int *));

    for(int i = 0; i < N; i++) {
        result[i] = (int *) calloc(N, sizeof(int));
        for(int j = 0; j < N; j++)
            for(int k = 0; k < N; k++)
                result[i][j] += m1[i][k] * m2[k][j];
    }

    return result;
}

void print_matrix(int **matrix, int N) {
    if(matrix == NULL)
        return;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

void free_matrix(int **matrix, int N) {
    if(matrix == NULL)
        return;

    for(int i = 0; i < N; i++)
        free(matrix[i]);
    free(matrix);
}

int main(int argc, char *argv[]) {
    srand(time(NULL));

    int N = argv[1][0] - '0';

    int **m1 = create_matrix(N);
    int **m2 = create_matrix(N);

    print_matrix(m1, N);
    printf("\n");
    print_matrix(m2, N);
    printf("\n");

    int **result = multiply_matrix(m1, m2, N);
    print_matrix(result, N);

    free_matrix(m1, N);
    free_matrix(m2, N);
    free_matrix(result, N);

    return 0;
}