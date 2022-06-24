/*
    Faça uma função que troca o valor de dois ponteiros
*/

#include <stdio.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    int a = 3, b = 5;

    swap(&a, &b);

    printf("a = %d\nb = %d\n", a, b);
    
    return 0;
}