#include <stdio.h>
#include <stdlib.h>

void write(int v[], int N) {
    FILE *file = fopen("register.txt", "w");

    for(int i = 0; i < N; i++)
        fprintf(file, "%d ", v+i);
    fprintf(file, "\n");
}

int ** read() {
    FILE *file = fopen("register.txt", "r");
    
}

int main() {
    
}