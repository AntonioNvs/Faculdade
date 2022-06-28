/*
    Faça uma função que receba um valor n e crie dinamicamente um vetor de n
    elementos e retorne um ponteiro. Crie uma função que receba um ponteiro para um
    vetor e um valor n e imprima os n elementos desse vetor. Construa também uma
    função que receba um ponteiro para um vetor e libere esta área de memória. Ao final,
    crie uma função principal que leia um valor n e chame a função criada acima. Depois,
    a função principal deve ler os n elementos desse vetor. Então, a função principal deve
    chamar a função de impressão dos n elementos do vetor criado e, finalmente, liberar a
    memória alocada através da função criada para liberação.
*/

#include <stdio.h>
#include <stdlib.h>

int * create_vector(int N) {
    return (int *) malloc(N*sizeof(int));
}

void print_vector(int *v, int N) {
    for(int i = 0; i < N; i++)
        printf("%d ", *(v+i));
    printf("\n");
}

void free_vector(int *v) {
    free(v);
}

int main() {
    int N;
    scanf("%d", &N);

    int *v = create_vector(N);

    if(v == NULL) {
        return 1;
    }

    for(int i = 0; i < N; i++)
        scanf("%d", v+i);

    print_vector(v, N);

    free_vector(v);

    return 0;
}