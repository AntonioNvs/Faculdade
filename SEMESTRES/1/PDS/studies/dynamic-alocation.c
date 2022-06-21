#include <stdio.h>
#include <stdlib.h>

/*
  Anotações:
    - Todas as funções são da <stdlib.h>
   
    - A função da alocação dinâmica é reservar espaço para variáveis
   durante a execução do programa, não apenas durante sua escrita.
   
    - Criado uma variável-ponteiro que armazena o valor do primeiro
   índice da lista.

    - As quatro funções principais são: malloc, calloc, realloc e free
   
    - Operador sizeof(): retorna o número de bytes de um tipo de dado

    - malloc():
     - Recebe como parâmetro o número de bytes a ser alocado
     - Retorna um ponteiro do tipo void para o primeiro byte alocado
     - Atribui-se esse retorno por meio de type cast.
     - Se não haver memória o suficiente, é retornado um ponteiro nulo
    
     Exemplo: int *p; p = (int *) malloc(50*sizeof(int));
    
    - calloc():
     - Faz a mesma funcionalidade que o malloc()
     - É passado como parâmetro a quantidade de posições e o quanto cada
       posição ocupa
     - Atribui zero para todos os valores do endereço de memória alocado

    - realloc():
     - Serve para realocar memória dado o ponteiro alocado e o novo espaço
     - Modifica o alocamento feito para o novo especificado como parâmetro
     - É retornado um ponteiro, pois o bloco de endereços talvez necessite
       ser movido para se adequar ao novo tamanho
     - Se o ponteiro dado for nulo, a função será igual um malloc()
     - Se num é zero, a memória apontada é liberada

     Exemplo: p = realloc(p, 3*sizeof(int));

    - free():
     - As variáveis alocadas pelas funções não são liberadas automaticamente
       ao término do programa, assim, essa função libera o espaço das memórias
       alocadas
     - Recebe o ponteiro como parâmetro

    - Alocação de matrizes:
     - Dado o tipo no sizeof do malloc como o tipo da variável a ser apontada,
       é retornado um ponteiro que aponta para a alocação de ponteiros, logo, 
       um ponteiro duplo.
     - Para cada vez que eu for usar a memória alocada para um certo endereço M[i],
       eu preciso alocar memória que será armazenada nesse endereço, criando assim
       uma matriz. 

 Aviso: SEMPRE, EM QUALQUER USO DE MALLOC, VERIFICA-SE O PONTEIRO É NULO
        E FAÇA O TRATAMENTO DE RETORNO DE ERRO.

*/

int main() {
    int *p, *c;
    
    c = (int *) malloc(50*sizeof(int));
    p = (int *) calloc(50, sizeof(int));

    // Tratamento caso não seja possível alocar
    if(c == NULL || p == NULL) {
      printf("Insuficient memory.\n");
      system("pause");
      return 1;
    }

    printf("%d\n", c[25]);
    printf("%d\n", p[20]);
    
    c = realloc(c, 10*sizeof(int));

    // Liberando
    free(c);
    free(p);

    // Alocando em matrizes!
    // Ponteiro que aponta para um ponteiro que aponta para um inteiro.
    int **M, m = 20, n = 10; 
    
    // Alocando memória para os ponteiros que irão apontar para as linhas
    M = (int **) malloc(sizeof(int *)*m);

    // Tratamento caso não seja possível alocar
    if(M == NULL) {
      printf("Insuficient memory.\n");
      return 1;
    }

    // Para cada ponteiro i, é alocado a memória respectiva para aquela
    // linha

    for(int i = 0; i < m; i++) {
      M[i] = (int * ) malloc(sizeof(int)*n);
      // Tratamento caso não seja possível alocar
      if(M[i] == NULL) {
        printf("Insuficient memory.\n");
        return 1;
      }
    }

    return 0;
}