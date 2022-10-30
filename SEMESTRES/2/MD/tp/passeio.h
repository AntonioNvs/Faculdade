#ifndef PASSEIO_TP
#define PASSEIO_TP

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define N 8
#define ll long long int
#define min(a,b) ((a) < (b) ? (a) : (b))


// Definindo estrutura de tipos chaves
typedef struct Mov {
    int x;
    int y;
} Moviment;

typedef struct Heuristic {
    Moviment * movs;
    int qtd;
} HeuristicReturn;

// Verificando se a posição de análise se encaixa nos limites e requisitos exigidos
int limits(int x, int y, int grid[N+1][N+1]) {
    return x >= 1 && x <= N && y >= 1 && y <= N && grid[x][y] == 0;
}

// Retorna o número de movimentos possíveis que a posição atual pode fazer
int get_conectivity_degree(int x, int y, int grid[N+1][N+1], Moviment addition[8]) {
    int count = 0;

    for(int i = 0; i < 8; i++)
        if(limits(x + addition[i].x, y + addition[i].y, grid))
            count++;

    return count;
}

void swap_on_sort(int i, int j, int comparation[8][2]) {
    int value1 = comparation[i][0], value2 = comparation[i][1];
    comparation[i][0] = comparation[j][0];
    comparation[i][1] = comparation[j][1];
    comparation[j][0] = value1;
    comparation[j][1] = value2;
}

// A partir da heurística dos graus de conectividade de cada movimento, retorna
// uma lista ordenada dos movimentos com o menor grau descrito.
HeuristicReturn heuristic(int x, int y, int grid[N+1][N+1], Moviment addition[8]) {
    int qtd = 0;
    int comparation[8][2];
    
    // Obtendo todos os movimentos possíveis junto com seus graus de conectividade
    for(int i = 0; i < 8; i++) {
        int nx = x + addition[i].x;
        int ny = y + addition[i].y;

        if(limits(nx, ny, grid)) {
            comparation[qtd][0] = get_conectivity_degree(nx, ny, grid, addition);
            comparation[qtd][1] = i;
            qtd++;
        }
    }

    // Ordenando a matriz de comparação pelos graus de conectividade
    for(int i = 0; i < qtd; i++)
        for(int j = i+1; j < qtd; j++)
            if(comparation[j][0] < comparation[i][0]) {
                swap_on_sort(i, j, comparation);
            } else if(comparation[j][0] == comparation[i][0]) {
                double dist1 = sqrt(
                    pow(min(x + addition[comparation[i][1]].x, N - x + addition[comparation[i][1]].x), 2) + 
                    pow(min(y + addition[comparation[i][1]].y, N - y + addition[comparation[i][1]].y), 2)
                );

                double dist2 = sqrt(
                    pow(min(x + addition[comparation[j][1]].x, N - x + addition[comparation[j][1]].x), 2) + 
                    pow(min(y + addition[comparation[j][1]].y, N - y + addition[comparation[j][1]].y), 2)
                );

                if(dist2 < dist1)
                    swap_on_sort(i, j, comparation);
            }

    // Criando o vetor de movimentos com as adições desejadas
    Moviment * moviments = (Moviment *) malloc(qtd * sizeof(Moviment));
    for(int i = 0; i < qtd; i++) {
        int idx = comparation[i][1];
        moviments[i].x = x + addition[idx].x;
        moviments[i].y = y + addition[idx].y;
    }

    HeuristicReturn result = {moviments, qtd};
    return result;
}

// Função de backtracking, que utiliza da heurística para prever os movimentos
// a serem analisados
int backtracking(int x, int y, int count, int grid[N+1][N+1], Moviment addition[8], ll *homes, ll *setbacks) {
    *homes = *homes + 1;

    int k = 0;
    int finish = count > N*N;

    HeuristicReturn result = heuristic(x, y, grid, addition);

    while(k < result.qtd && !finish) {

        int nx = result.movs[k].x;
        int ny = result.movs[k].y;

        grid[nx][ny] = count;

        finish = backtracking(nx, ny, count + 1, grid, addition, homes, setbacks);
        
        // Caso não tenha finalizado nesse caso, é atualizado a 
        // variável de retrocedimentos e tenta em uma nova casa
        if(!finish) {
            *setbacks = *setbacks + 1;
            grid[nx][ny] = 0;
        }
    }
    
    free(result.movs);

    return finish;
}

// Reseta todas as casas do grid para 0
void reset_grid(int grid[N+1][N+1]) {
    for(int i = 0; i <= N; i++)
        for(int j = 0; j <= N; j++)
            grid[i][j] = 0;
}

// Printa, de forma espaçada, todas as casas do grid
void print_on_file(int grid[N+1][N+1], ll *homes, ll *setbacks) {
    FILE * src = fopen("saida.txt", "a");
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(grid[i][j] >= 10)
                fprintf(src, "%d ", grid[i][j]);
            else
                fprintf(src, " %d ", grid[i][j]);
        }
        fprintf(src, "\n");
    }
    fprintf(src, "%lld %lld\n", *homes, *setbacks);
    fclose(src);
}

void passeio(int x, int y) {

    // Variáveis globais
    ll homes = 0;
    ll setbacks = 0;
    int grid[N+1][N+1];
    Moviment addition[8] = {{-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}};

    // Zerando todo o grid para não haver problemas
    reset_grid(grid);
    
    grid[x][y] = 1;

    backtracking(x, y, 2, grid, addition, &homes, &setbacks);
    
    print_on_file(grid, &homes, &setbacks);
}

#endif