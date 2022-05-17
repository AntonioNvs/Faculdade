#include <stdio.h>
#include <string.h>

typedef struct Person {
  char name[50];
  unsigned int age;
  float wage;
} person;

int main() {
  person peoples[4];

  char operation[12], name[25];
  int age, i = 0;
  float wage;


  while(1) {
    scanf("%s", operation);
    
    if(!strcmp(operation, "inserir")) {
      scanf("%s %d %f", name, &age, &wage);

      if(i == 4) {
        printf("Espaço insuficiente.\n");
        continue;
      }

      for(int j = 0; name[j] != '\0'; j++)
        peoples[i].name[j] = name[j];

      peoples[i].name[strlen(name)] = '\0';
      peoples[i].age = age;
      peoples[i].wage = wage;

      printf("Registro %s %d %f inserido\n", peoples[i].name, peoples[i].age, peoples[i].wage);

      i++;
    } else {
      scanf("%s", name);

      int exists = 0;

      for(int k = 0; k < i; k++) {
        if(!strcmp(peoples[k].name, name)) {
          printf("Registro %s %d %f\n", peoples[k].name, peoples[k].age, peoples[k].wage);
          exists = 1;
          break;
        }
      }

      if(!exists) {
        printf("Registro ausente\n");
      }
    }
  }

  return 0;
}