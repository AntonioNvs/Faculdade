#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "passeio.h"

#define N_TESTE 1000

void validar_movimento(int resul[3], int atual[2], int proximo[2]) {

    int atual_i = atual[0];
    int atual_j = atual[1];
    int proximo_i = proximo[0];
    int proximo_j = proximo[1];

    int movimento_i = 0;
    int movimento_j = 0;

    if (atual_i > proximo_i)
    {
        movimento_i = atual_i - proximo_i;
    }
    else{
        movimento_i = proximo_i - atual_i;
    }

    if (atual_j > proximo_j) {
        movimento_j = atual_j - proximo_j;
    }
    else {
        movimento_j = proximo_j - atual_j;
    }

    int movimentos_possiveis[8][2] = {{-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}};
    int movimento[2] = {movimento_i, movimento_j};

    resul[0] = 0;
    resul[1] = movimento[0];
    resul[2] = movimento[1];

    for (int i=0; i<8; i=i+1){
        if ((movimento[0] == movimentos_possiveis[i][0]) & (movimento[1] == movimentos_possiveis[i][1])){
            resul[0] = 1;
            return;
        }
    }

}

void exibir(int (*matriz)[8]){

    printf("Matriz\n");
    for(int i = 0; i < 8; ++i)
    {
        for(int j = 0; j < 8; ++j)
            printf("%-3d ", matriz[i][j]);
        puts("");
    }
}

int verificar(int (*matriz)[8], int visitadas, int retrocedidas, int posicao_inicial_original[]){

    if (visitadas - retrocedidas != 64) {
        printf("Erro: diferença no número de casas visitas\n");
        printf("Visitadas: %d | retrocedidas: %d\n", visitadas, retrocedidas);
        exit(2);
    }

    int movimento_posicao[65][2], indice_movimento = -1, atual[2] = {-1, -1}, proximo[2] = {-1, -1}, resul[3] = {-1, -1, -1};
    // inicializar a mariz que contém as coordenadas das posições visitadas em cada um dos 64 movimentos corretos
    for(int i=1; i<=64; i++){
        movimento_posicao[i][0] = -1;
        movimento_posicao[i][1] = -1;
    }

    // verificar se os valores da matriz estão entre 1 e 64 e coletar os pares de movimento x posicao
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            indice_movimento = matriz[i][j];

            if ((indice_movimento >= 1 & indice_movimento <= 64) && (movimento_posicao[indice_movimento][0] == -1 && movimento_posicao[indice_movimento][1] == -1)) {
                movimento_posicao[indice_movimento][0] = i;
                movimento_posicao[indice_movimento][1] = j;
//                if (indice_movimento == 1){
//                    printf("x: %d y: %d ---- indice %d", movimento_posicao[indice_movimento][1], movimento_posicao[indice_movimento][1], indice_movimento);
//                }
            }
            else {
                printf("Posição da matriz incorretamente preenchida ou movimento repetido. Movimento %d da posição (%d, %d)\n",
                       indice_movimento, i, j);
                //printf(" Indice do movimento %d, Posição do movimento (%d, %d)\n", indice_movimento, movimento_posicao[indice_movimento][0], movimento_posicao[indice_movimento][1]);
                exit(2);
            }
        }
    }

    // Verificar se a posição inicial é a informada na entrada do algoritmo
    if (movimento_posicao[1][0] != posicao_inicial_original[0] || movimento_posicao[1][1] != posicao_inicial_original[1]){
        printf("A posição inicial (%d, %d) é diferente da entrada (%d, %d)", movimento_posicao[1][0], movimento_posicao[1][1], posicao_inicial_original[0], posicao_inicial_original[1]);
        exit(2);
    }
    

    // Percorrer os movimentos (de 1 a 64) e verificar se as posições são alcançadas a partir de movimentações válidas (formato de L) e se não há posição repetida ou não visitada
    for(int i=2; i <= 64; i++) {

        atual[0] = movimento_posicao[i - 1][0];
        atual[1] = movimento_posicao[i - 1][1];
        proximo[0] = movimento_posicao[i][0];
        proximo[1] = movimento_posicao[i][1];


        if ((atual[0] == -1 || atual[1] == -1) || (proximo[0] == -1 || proximo[1] == -1)) {
            printf("Posições (%d, %d) e (%d, %d) não visitadas\n", atual[0], atual[1], proximo[0], proximo[1]);
            exit(2);
        }

        validar_movimento(resul, atual, proximo);
        if (resul[0] != 1) {
            printf("Movimento de %d para %d inválido. Movimentação (%d, %d)\n", i - 1, i, resul[1], resul[2]);
            exit(2);
        }

    }

    printf("Correto\n");

}

void inicializar(int (*matriz)[8]){

    for(int i = 0; i < 8; ++i)
    {
        for(int j = 0; j < 8; ++j)
            matriz[i][j] = -1;
    }
}

int ler_e_verificar(int rows, int cols, int matriz[][8], const char* filename, int (*posicao_inicial_original)[2])
{

    FILE *pf;
    int count = 1, resultado_count = 0;
    int ret;
    pf = fopen (filename, "r");

    int visitadas, retrocedidas;

    // Ajuste das posições
    for(int i = 0; i < N_TESTE; i++){
        posicao_inicial_original[i][0] -= 1;
        posicao_inicial_original[i][1] -= 1;
    }

    if (pf == NULL)
        return 0;


    while (1) {
        printf("----------------------------\n");
        printf("Verificando caso de teste %d\n", resultado_count);
        printf("----------------------------\n");
        // inicializar matriz
        visitadas = -1000;
        retrocedidas = -1000;
        inicializar(matriz);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j)
                ret = fscanf(pf, "%d", matriz[i] + j);
                if (ret == EOF){
                    if (count == 1) {
                        printf("Final do arquivo\n");
                        return 0;
                    }
                    else {
                        printf("Arquivo incompleto\n");
                        exit(2);
                    }
                }
            count = count + 1;
            if (count == 9) {
                count = 1;
            }
        }
        ret = fscanf(pf, "%d %d", &visitadas, &retrocedidas);
        if (ret == EOF){
            printf("Final do arquivo\n");
            return 0;
        }
        exibir(matriz);
        verificar(matriz, visitadas, retrocedidas, posicao_inicial_original[resultado_count]);
        resultado_count++;
        if (resultado_count >= N_TESTE){
            printf("Verificação correta");
            exit(2);
        }
    }
    fclose (pf);
}




int main() {

    int x, y;
    int posicao_inicial_original[N_TESTE][2];
    time_t t;
    srand((unsigned) time (&t));

    posicao_inicial_original[0][0] = 4;
    posicao_inicial_original[0][1] = 7;

    for (int i = 1; i < N_TESTE; i++){

        x = rand() % 8 + 1;
        y = rand() % 8 + 1;
        posicao_inicial_original[i][0] = x;
        posicao_inicial_original[i][1] = y;
    }
    // Aplicar os casos de teste
    for (int i = 0; i < N_TESTE; i++){

        passeio(posicao_inicial_original[i][0], posicao_inicial_original[i][1]);
    }

    // Verificar os resultados
    int matrix[8][8];

    ler_e_verificar(8, 8, matrix, "saida.txt", posicao_inicial_original);
    return 0;
}
