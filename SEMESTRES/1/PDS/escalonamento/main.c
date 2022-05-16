#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int M, N;
int steps = 1;

float matrix[MAX][MAX];

void print_matrix(float m[M][N]) {
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++)
            printf("%0.2f ", matrix[i][j]);
        printf("\n");
    }
    printf("\n");
}

// Operações com as linhas
void divide_by_num(int row, float num) {
    for(int j = 0; j < N; j++)
        matrix[row][j] = matrix[row][j] / num;
}


void sum_a_row_by_another_row(int send_row, int rec_row, float fac) {
    for(int j = 0; j < N; j++) {
        matrix[rec_row][j] += fac*matrix[send_row][j];
    }
}

void second_escalation(int idx);


void change_row(int r1, int r2) {
    int temp[N];

    for(int i = 0; i < N; i++) {
        temp[i] = matrix[r1][i];
    }

    for(int i = 0; i < N; i++) {
        matrix[r1][i] = matrix[r2][i];
        matrix[r2][i] = temp[i];
    }
}

void first_escalation(int idx) {
    // Identificar a linha a qual a variável atual é diferente de 0
    int var;
    for(int i = idx; i < M; i++)
        if(matrix[i][idx] != 0.0) {
            var = i;
            break;
        }
    
    if(var > idx) {
        change_row(var, idx);
        printf("1. Passo: %d\n", steps++);
        print_matrix(matrix);
        var = idx;
    }

    // Transformando o pivo em 1
    divide_by_num(var, matrix[var][idx]);

    printf("1. Passo: %d\n", steps++);
    print_matrix(matrix);

    // Zerando as outras linhas da coluna da variável
    for(int i = var+1; i < M; i++) {
        sum_a_row_by_another_row(var, i, -1.0*matrix[i][idx]);
        
    }

    printf("1. Passo: %d\n", steps++);
    print_matrix(matrix);

    if(idx != M-1)
        first_escalation(idx+1);
    else
        second_escalation(idx);
}

void second_escalation(int idx) {
    for(int i = idx-1; i >= 0; i--) {
        sum_a_row_by_another_row(idx, i, -1.0*matrix[i][idx]);    
    }

    printf("2. Passo: %d\n", steps++);
    print_matrix(matrix);

    if(idx != 1)
        second_escalation(idx-1);
}

int main() {
    printf("Digite o tamanho da sua matriz espaçado: ");
    scanf("%d %d", &M, &N);

    if(N != M+1) {
        printf("\nSua matriz está incompleta em tamanho. (M+1 != N");
        return 0;
    }

    // Pedindo para digitar a matriz dada
    printf("\n\nDigite sua matriz:\n");

    for(int i = 0; i < M; i++)
        for(int j = 0; j < N; j++)
            scanf("%f", &matrix[i][j]);
    
    printf("\n");
    
    // Verificando a viabilidade da matriz: todas as colunas de coeficientes devem
    // ter pelo menos um elemento não nulo.

    for(int j = 0; j < N-1; j++) {
        int has_non_zero = 0;

        for(int i = 0; i < M; i++)
            if(matrix[i][j] != 0.0)
                has_non_zero = 1;

        if(!has_non_zero) {
            printf("Todos os coeficientes tem que ter pelo menos um que o represente.\n");
            return 0;
        }
    }

    first_escalation(0);

    return 0;
}