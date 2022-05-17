#include <stdio.h>
#include <string.h>

typedef struct Address {
  char street[50];
  int number;
  char state[50];
} address;

typedef struct Person {
  char name[50];
  unsigned int age;
  float wage;
  address address;
} person;

int main() {
  person peoples[4];

  char operation[12], name[25], street[50], state[50];
  int age, i = 0, number;
  float wage;


  while(1) {
    scanf("%s", operation);
    
    if(!strcmp(operation, "inserir")) {
      scanf("%s %d %f %s %d %s", name, &age, &wage, street, &number, state);

      if(i == 4) {
        printf("Espaço insuficiente.\n");
        continue;
      }

      for(int j = 0; name[j] != '\0'; j++)
        peoples[i].name[j] = name[j];

      for(int j = 0; name[j] != '\0'; j++)
        peoples[i].address.street[j] = street[j];

      for(int j = 0; name[j] != '\0'; j++)
        peoples[i].address.state[j] = state[j];

      peoples[i].name[strlen(name)] = '\0';
      peoples[i].address.street[strlen(street)] = '\0';
      peoples[i].address.state[strlen(state)] = '\0';
      peoples[i].age = age;
      peoples[i].wage = wage;
      

      printf("Registro %s %d %f %s %d %s inserido\n", peoples[i].name, peoples[i].age, peoples[i].wage, street, number, state);

      i++;
    } else if(!strcmp(operation, "mostrar")){
      scanf("%s", name);

      int exists = 0;

      for(int k = 0; k < i; k++) {
        if(!strcmp(peoples[k].name, name)) {
          printf("Registro %s %d %f %s %d %s\n", peoples[k].name, peoples[k].age, peoples[k].wage, peoples[k].address.street, peoples[k].address.number, peoples[k].address.state);
          exists = 1;
          break;
        }
      }

      if(!exists) {
        printf("Registro ausente\n");
      }

    } else {
      scanf("%s %d %f %s %d %s", name, &age, &wage, street, &number, state);
      int exists = -1;

      for(int k = 0; k < i; k++) {
        if(!strcmp(peoples[k].name, name)) {
          exists = k;
          break;
        }
      }

      if(exists == -1) {
        printf("Registro ausente para alteracao\n");
        continue;
      }

      for(int j = 0; name[j] != '\0'; j++)
        peoples[exists].name[j] = name[j];

      for(int j = 0; name[j] != '\0'; j++)
        peoples[exists].address.street[j] = street[j];

      for(int j = 0; name[j] != '\0'; j++)
        peoples[exists].address.state[j] = state[j];

      peoples[exists].name[strlen(name)] = '\0';
      peoples[exists].address.street[strlen(street)] = '\0';
      peoples[exists].address.state[strlen(state)] = '\0';
      peoples[exists].age = age;
      peoples[exists].wage = wage;

      printf("Registro %s %d %f %s %d %s alterado\n", peoples[exists].name, peoples[exists].age, peoples[exists].wage, street, number, state);
    }
  }

  return 0;
}