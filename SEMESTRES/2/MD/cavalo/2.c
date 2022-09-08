#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 8
#define ll long long int
#define max(x, y) (((x) > (y)) ? (x) : (y))
#define min(x, y) (((x) < (y)) ? (x) : (y))

typedef struct Mov {
    int x;
    int y;
} Moviment;

typedef struct Heuristic {
    Moviment * movs;
    int qtd;
} HeuristicReturn;

// Variáveis globais
ll homes = 0;
ll setbacks = 0;
int grid[N+1][N+1];
int blocks[2][2] = {0, 0, 0, 0};

// Declarando as funções utilizadas antes da 'main' e construindo-as logo após
int backtracking(int x, int y, int count);
int limits(int i, int j);
float euclidian_distance(int x, int y);
void print_matrix(int m[N+1][N+1]);
HeuristicReturn heuristic(int x, int y);


int main() {
    for(int i = 0; i <= N; i++)
        for(int j = 0; j <= N; j++)
            grid[i][j] = 0;

    int initial_x = 1, initial_y = 1;
    
    grid[initial_x][initial_y] = 1;
    backtracking(initial_x, initial_y, 2);

    print_matrix(grid);

    return 0;
}


// Verificando se certo movimento é possível, dado o tabuleiro atual
int limits(int i, int j) {
    return i >= 1  && i <= N && j >= 1 && j <= N && grid[i][j] == 0;
}

// Preenchendo o tabuleiro a partir de uma recursão de retrocedimento
int backtracking(int x, int y, int count) {
    int crr_mov = 0;
    int finish = count > N*N;

    if(count > 62)
        printf("%d\n", count);

    HeuristicReturn result = heuristic(x, y);
    Moviment * moviments = result.movs;

    while(!finish && crr_mov < result.qtd) {
        int nx = moviments[crr_mov].x;
        int ny = moviments[crr_mov].y;

        // printf("%d %d\n", nx, ny);

        grid[nx][ny] = count;
        blocks[(int) (nx-1) / 4][(int) (ny-1) / 4]++;

        finish = backtracking(nx, ny, count + 1);
        
        if(!finish) {
            grid[nx][ny] = 0;
            blocks[(int) (nx-1) / 4][(int) (ny-1) / 4]--;
        }

        crr_mov++;
    }

    free(moviments);

    return finish;
}

// Heuristíca para seleção de uma lista ordenada dos melhores possíveis movimentos
HeuristicReturn heuristic(int x, int y) {
    // Lista de acréscimos da posição atual que o cavalo pode realizar em um tabuleiro
    Moviment addition[8] = {{-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}};

    int qtd_mov = 0;

    Moviment * moviments = (Moviment *) malloc(8 * sizeof(Moviment));

    for(int i = 0; i < 8; i++) {
        int nx = x + addition[i].x;
        int ny = y + addition[i].y;

        if(limits(nx, ny)) {
            moviments[qtd_mov].x = nx;
            moviments[qtd_mov].y = ny;
            qtd_mov++;
        }
    }
    moviments = (Moviment *)realloc(moviments, qtd_mov * sizeof(Moviment));
    
    for(int i = 0; i < qtd_mov; i++) {
        for(int j = i+1; j < qtd_mov; j++) {
            Moviment a = moviments[i];
            Moviment b = moviments[j];
            
            
            if(blocks[(a.x-1) / 4][(a.y-1) / 4] < blocks[(b.x-1) / 4][(b.y-1) / 4]) {
                Moviment temp = moviments[i];
                moviments[i] = moviments[j];
                moviments[j] = temp;
            }
        }
    }

    HeuristicReturn result = {moviments, qtd_mov};
    return result;
}

// Calcula a distância euclidiana da parte mais próxima da borda
float euclidian_distance(int x, int y) {
    float nx = min(x, N-x);
    float ny = min(y, N-y);

    return sqrt(pow(nx, 2) + pow(ny, 2));
}

// Imprimindo a matriz na linha de comando
void print_matrix(int m[N+1][N+1]) {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(m[i][j] >= 10)
                printf("%d ", m[i][j]);
            else
                printf(" %d ", m[i][j]);
        }
        printf("\n");
    }
}