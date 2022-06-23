#include <stdio.h>

/*
  ENUM
    - Serve para ser uma lista de constantes, que,
      para fins de otimização, cada palavra será armazenada
      como um índice para ela.
    - Pode ser usado para dias da semana, itens de uma loja, etc.
    - O primeiro valor da enumeração é identificado como 0, o segundo
      por um, e assim por diante.
    - Pode definir qual valor um identificador será, e os próximos não
      especificados será sempre um maior que o anterior
    - Pode definir outros valores além de inteiro.

  UNION
    - Se aparenta com a struct, entretanto, sua principal função é
      otimizar memória
    - Estrutura de memória compartilhada, reservando a memória somente
      do maior valor, dividindo ela para todos os parâmetros
    - Usar a union somente quando quero criar várias variáveis mas não
      acessadas ao mesmo tempo
*/

// Definindo uma enumeração dos dias da semana
enum Week {
    Sunday,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday
};

// Criando uma representação de um nó de uma árvore binária
union Node  {
    unsigned short value;
    union Node *left;
    union Node *right;
};

int main() {
    // Declarando uma variável que receberá um valor da enumeração
    enum Week workout_day;

    // Atribuindo um dia da semana a variável
    workout_day = Sunday;
    printf("Day: %d\n", workout_day);

    // Soma de identificadores
    enum Week day1, day2, day3;
    day1 = Monday;
    day2 = Wednesday;
    day3 = Monday + Wednesday;
    printf("Sum: %d\n", day3);


    // Verificando a função da union na prática.
    union Node n1, n2;
    n1.value = 10;
    n2.value = 5;
    n1.left = &n2;

    printf("Left value = %d\n", (*n1.left).value);
    // Tem que ser diferente do que foi definido
    printf("Value = %d\n", n1.value); 

    return 0;
}