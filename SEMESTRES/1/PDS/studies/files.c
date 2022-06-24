#include <stdio.h>
#include <stdlib.h>

/*
 Anotações:
  - FILE é o tipo que armazena um arquivo
  
  - Para criar/abrir um arquivo, use a função fopen()
  
  - fopen():
   - Informe o caminho do arquivo como primeiro parâmetro
   - O caminho deve ser da raiz do computador e incluir o nome e 
     tipo do arquivo (.txt, .csv). Obs.: se não incluir até a raiz,
     então será usado o  diretório em que foi executado o programa
   - O segundo parâmetro é o que você irá fazer com arquivo
    - "r": ler
    - "w": escrever / criar um arquivo, caso não exista.
    - "a": acrescentar algo no arquivo
   - NOTA: TODA VEZ QUE VOCÊ USA "w" EM UM ARQUIVO, TODO O CONTEÚDO
     NELE É APAGADO

  - fprintf()
   - Dado o ponteiro FILE e uma string/char, é escrito no arquivo o 
     determinado

  - fscanf()
   - Funcionamento idêntico a função scanf(), somente com a adição
     do primeiro parâmetro que é o ponteiro do arquivo
   - É feito o esquema de leitura pela linha
   - Tem o problema de necessitar que o arquivo tenha a mesma estrutura
     especificada.

   - fgets()
    - Recebe a string que será armazenada a leitura, o tamanho a ser lido
      e em qual arquivo é para ser feito a leitura
    - Ler a linha até encontrar a quebra de linha
    - É retornado o texto lido e NULL caso não tenha mais

   - fputs()
    - Escrevendo no arquivo um vetor de char dado como parâmetro.

   - fread()
    - Recebe o ponteiro onde a leitura será arquivada, o tamanho em bytes
      do tipo guardado, a sua quantidade e onde será lido.
    - Usado para tipos binários de arquivo.
    - Retorna a quantidade de item lidos.

    Exemplo: fread(&value, sizeof(int), 1, file);

   fwrite()
    - A mesma estrutura que o fread(), a diferença é que irá escrever a 
      variável dada como primeiro parâmetro no arquivo
    - Usado para tipos binários de arquivo.
    - Retorna a quantidade de item escritos.

    Exemplo: fwrite(&value, sizeof(int), 1, file);

  NOTA: SEMPRE LEMBRE DE FECHAR O ARQUIVO COM FCLOSE DEPOIS DE SEU USO
*/

int main() {
    // Instanciando uma variável que irá guardar o arquivo feito
    FILE *file;
    
    // Criando um arquivo e salvando ele no ponteiro
    file = fopen("test.txt", "w");

    // Escrever algum texto no arquivo
    fprintf(file, "Hello World\n");
    
    // Salvando o arquivo com as modificações
    fclose(file);

    // Abrindo o arquivo (obrigatório a sua existência para funcionamento correto)
    file = fopen("test.txt", "r");
    
    // Tratamento caso o arquivo não exista
    if(file == NULL) {
        printf("The specific file doesn't exist.\n");
        system("pause");
        return 1;
    }

    // Lendo a primeira linha com 'fscanf'
    char txt[100];
    fscanf(file, "%s", txt);
    printf("%s\n", txt);
    fclose(file);
    // PROBLEMA: não lê a linha inteira!! somente a primeira palavra.

    // Criando um sistema que lê todas as linhas com fgets()
    file = fopen("test.txt", "r");
    while(fgets(txt, 100, file) != NULL) {
        printf("%s", txt);
    }
    fclose(file);

    // Abrindo o arquivo para anexar
    file = fopen("test.txt", "a");
    
    // Tratamento caso o arquivo não exista
    if(file == NULL) {
        printf("The specific file doesn't exist.\n");
        system("pause");
        return 1;
    }

    fprintf(file, "Hello universe.\n");
    
    // Adicionando um array de char  
    char phrase[20] = "Hi!!\n"; 
    fputs(phrase, file); 
    
    // Adicionando um caracter específico
    char c = 'a';
    fputc(c, file);

    fclose(file);

    return 0;
}