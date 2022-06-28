#include <stdio.h>
#include <stdlib.h>

int N, M;

int search(int i, int j, int v, int ** matrix) {
    if(i == N)
        return 0;

    if (matrix[i][j] == v)
        return 1;
    
    if (j + 1 < M)
        return search(i, j+1, v, matrix);
    else
        return search(i+1, 0, v, matrix); 
}

int main() {
    scanf("%d %d", &N, &M);

    int **matrix = (int **) malloc(sizeof(int *) * N);

    for(int i = 0; i < N; i++) {
        matrix[i] = (int *) malloc(sizeof(int) * M);

        for(int j = 0; j < M; j++)
            scanf("%d", &matrix[i][j]);
    }

    char option;
    int x, y, v;
    
    while(scanf(" %c", &option) != EOF) {
        if(option == 'e') {
            scanf("%d %d %d", &x, &y, &v);

            matrix[x][y] = v;
        } else {
            scanf("%d", &v);
            printf("%d\n", search(0, 0, v, matrix));
        }
    }
}