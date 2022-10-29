#include <stdio.h>

#define MAXN 12

int grid[MAXN][MAXN];

int N;
int movL[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int movC[] = {2, 1, -1, -2, -2, -1, 1, 2};

long long int homes = 0LL, setbacks = 0LL;

int limits(int i, int j) {
    return i >= 1  && i <= N && j >= 1 && j <= N && grid[i][j] == 0;
}

int backtracking(int i, int j, int count) {
    int k = 0;
    // Verificando se o tabuleiro já foi completado
    int finish = count > N*N;
    
    homes++;
    
    // Iterando por todos os movimentos do cavalo
    while(!finish && k < 8) {
        int ni = i + movL[k];
        int nj = j + movC[k];
        
        // Se o novo movimento for válido, testa ele.
        if(limits(ni, nj)) {
            grid[ni][nj] = count;
            
            finish = backtracking(ni, nj, count + 1);

            if(!finish) {
                setbacks++;
                grid[ni][nj] = 0;
            } else return finish;
        }
        k++;
    }

    return finish;
}

int main() {
    for(int i = 0; i <= MAXN; i++)
        for(int j = 0; j <= MAXN; j++)
            grid[i][j] = 0;

    scanf("%d", &N);
    grid[1][1] = 1;

    backtracking(1, 1, 2);

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++)
            printf("%d ", grid[i][j]);
        printf("\n");
    }
    printf("\n");
    printf("Was made %lld recursions and analysed %lld setbacks to build this matrix with %dx%d size.\n", homes, setbacks, N, N);

    return 0;
}