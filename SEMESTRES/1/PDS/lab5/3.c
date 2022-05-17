#include <stdio.h>
#include <string.h>

typedef struct Product {
  char name[50];
  char brand[50];
  float price;
} product;

typedef struct InfoBrand {
  char brand[50];
  int qtd;
  float price;
} info;

int main() {
  product products[8];
  info informations[8];
  int k = 0;
  float sum = 0.0;

  for(int i = 0; i < 8; i++) {
    scanf("%s %s %f", products[i].name, products[i].brand, &products[i].price);

    int exists = -1;
    for(int j = 0; j < k; j++)
      if(!strcmp(informations[j].brand, products[i].brand)) {
        exists = j;
        break;
      }

    if(exists != -1) {
      informations[exists].qtd++;
      informations[exists].price += products[i].price;
    } else {
      for(int j = 0; products[i].brand[j] != '\0'; j++)
        informations[k].brand[j] = products[i].brand[j];

      informations[k].brand[strlen(products[i].brand)] = '\0';
      informations[k].qtd = 1;
      informations[k].price = products[i].price;

      k++;
    }
    sum += products[i].price;
  }

  for(int j = 0; j < k; j++)
    printf("%s %d\n", informations[j].brand, informations[j].qtd);

  printf("media total %f \n", sum / 8.0);

  for(int j = 0; j < k; j++)
    printf("media %s %f\n", informations[j].brand, informations[j].price / informations[j].qtd);

  return 0;
}
