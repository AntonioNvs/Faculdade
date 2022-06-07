#include <stdio.h>

#define NUM_ALUNOS 100

typedef struct {
  char matricula[7];
  unsigned int p1;
  unsigned int p2;
} Student;

void preencheAluno(Student *st) {
  scanf("%s", (*st).matricula);
  scanf("%d", &(*st).p1);
  scanf("%d", &(*st).p2);
}

int alunosAprovados(Student st[NUM_ALUNOS], int idx) {
  // Caso base
  if(idx >= NUM_ALUNOS)
    return 0;

  // Chamada recursiva
  if(st[idx].p1 + st[idx].p2 >= 60)
    return 1 + alunosAprovados(st, idx+1);

  return alunosAprovados(st, idx+1);
}


int main() {
  Student students[NUM_ALUNOS];

  char mat[7];
  int k = 0;

  while(k != NUM_ALUNOS) {
    preencheAluno(&students[k]);
    k++;
  }

  printf("%d", alunosAprovados(students, 0));

  return 0;
}