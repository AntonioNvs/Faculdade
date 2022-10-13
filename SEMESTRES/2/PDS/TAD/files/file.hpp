#pragma once

#include <string>
#include <vector>
#include <fstream>

using std::string;
using std::fstream;
using std::vector;

class File {
  public:
    // Construtor da classe
    File(string filename);

    // Incrementa uma string no arquivo
    void insert(string sentence);

    // Lê algo no arquivo e retorna um vetor
    vector<string> read();

    // Limpa o arquivo inteiro
    void clean(); 

    // Número de linhas do arquivo
    int nrows();

  private:
    string filename;

    // Abre o arquivo no modo especificado
    fstream open(char mode);
};