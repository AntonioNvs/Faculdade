#include <stdio.h>

#define MAXN 8

int grid[MAXN][MAXN];

int N;
int movL[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int movC[] = {1, 2, 2, 1, -1, -2, -2, -1};

long long int execs = 0, moviments = 0;

int limits(int i, int j) {
    return i >= 1  && i <= N && j >= 1 && j <= N && grid[i][j] == 0;
}

int fill(int i, int j, int count) {
    int k = 0;
    int finish = count > N*N;
    
    execs++;

    while(!finish && k < 8) {
        moviments++;
        int ni = i + movL[k];
        int nj = j + movC[k];

        if(limits(ni, nj)) {
            grid[ni][nj] = count;
            
            finish = fill(ni, nj, count + 1);

            if(!finish) {
                grid[ni][nj] = 0;
            }
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

    int x, y;
    x = y = N/2 + 1;
    grid[x][y] = 1;

    fill(x, y, 2);

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++)
            printf("%d ", grid[i][j]);
        printf("\n");
    }
    printf("\n");
    printf("Was made %lld recursions and analysed %lld moviments to build this matrix with %dx%d size.\n", execs, moviments, N, N);

    return 0;
}