#include <regex>
#include <math.h>
#include <string>
#include <vector>
#include <sstream>

#include "LineProcessor.hpp"

void LinePrinter::processaLinha(const std::string &str) {
  std::cout << str << std::endl;
}

bool ContadorPopRural::linhaValida(const std::string &str) const {
  // Neste exemplo usaremos expressoes regulares para verificar se uma linha
  // eh valida ou nao.
  //
  // Esta expressao regular eh formada por cinco partes. Cada uma dessas
  // partes eh um dos tres tipos de padrao regular abaixo:
  //
  // \\w+ eh qualquer palavra com um ou mais digitos, letras e sublinhas (_)
  // \\s* eh qualquer sequencia de zero ou mais espacos (inclui tab)
  // \\d+ eh qualquer sequencia de um ou mais digitos
  std::regex regularExpr("\\w+\\s*\\d+\\s*\\d+");
 
  // A funcao regex_match vai retornar verdadeiro se a string str casa-se com
  // a expressao regular que acabamos de criar:
  return std::regex_match(str, regularExpr);
}

void ContadorPopRural::processaLinha(const std::string &str) {
  //
  // Em geral eh mais facil ler dados de uma string se a string eh transformada
  // em um objeto do tipo stringstream:
  std::stringstream ss(str);
  //
  // Iremos ler os dados da string nestas tres variaveis abaixo:
  std::string nomePais;
  unsigned populacao, percUrbana;
  //
  // Como sabemos que a linha contem string int int, podemos fazer a leitura
  // facilmente usando o operador de streaming:
  ss >> nomePais >> populacao >> percUrbana;
  //
  // Note que precisamos arredondar o valor que serah impresso. O arredondamento
  // serah feito via a funcao floor. Ou seja, decimais serao sempre
  // arredondados para baixo:
  unsigned popRural = floor(populacao - (populacao * (percUrbana/100.0)));
  //
  // Uma vez encontrados os valores que precisam ser impressos, seguimos o
  // modelo do enunciado do exercicio:
  std::cout << popRural << " pessoas vivem no campo no " << nomePais <<
    std::endl;
}

bool ContadorNumNaturais::linhaValida(const std::string &str) const {
  bool hasNumber = false;
  for(char c : str) {
    int code = c-'\0';
    if(code >= 48 && code <= 57) hasNumber = true;
    else if(code != 32) return false;
  }
  return hasNumber;
}

void ContadorNumNaturais::processaLinha(const std::string &str) {
  unsigned count = 0;
  std::string number;

  for(char c : str) {
    int code = c-'\0';
    if(code == 32) {
      if(number != "")
        count += std::stoi(number);
      number = "";
    } 
    else number += c;
  }

  if(number != "")
    count += std::stoi(number);

  std::cout << count << std::endl;
}

bool LeitorDeFutebol::linhaValida(const std::string &str) const {
  std::regex regularExp("\\s*\\w+\\s*\\d+\\s*\\w+\\s*\\d+\\s*");
  return std::regex_match(str, regularExp);
}

void LeitorDeFutebol::processaLinha(const std::string &str) {
  std::stringstream ss(str);
  
  int first_score, second_score;
  std::string first_team, second_team;

  ss >> first_team >> first_score >> second_team >> second_score;

  if(first_score == second_score)
    std::cout << "Empate" << std::endl;
  else 
    std::cout << "Vencedor: " << (first_score > second_score ? first_team : second_team) << std::endl;
}

void ContadorDePalavras::processaLinha(const std::string &str) {
  std::string word;
  std::stringstream ss(str);

  unsigned count = 0;
  
  while(ss >> word)
    count++;

  std::cout << count << std::endl;
}

bool InversorDeFrases::linhaValida(const std::string &str) const {
  std::string word;
  std::stringstream ss(str);

  bool noHasPunct = true;

  while(ss >> word)
    noHasPunct &= std::regex_match(word, std::regex("\\b[a-zA-Z]+\\b"));

  return noHasPunct;
}

void InversorDeFrases::processaLinha(const std::string &str) {
  std::string word;
  std::stringstream ss(str);
  std::vector<std::string> words;

  while(ss >> word) words.push_back(word);

  for(int i = words.size()-1; i >= 0; i--)
    std::cout << words[i] << (i > 0 ? " " : "");
  std::cout << std::endl;
}

bool EscritorDeDatas::linhaValida(const std::string &str) const {
  std::regex dateFormat("\\s*\\d\\d?/\\d\\d?/\\d{4}");
  // TODO: Implemente este metodo
  // Note que você pode usar uma expressao regular como:
  // "\\s*\\d\\d?/\\d\\d?/\\d{4}" para saber se a linha eh valida:
  return std::regex_match(str, dateFormat);
}

void EscritorDeDatas::processaLinha(const std::string &str) {
  // TODO: Implemente este metodo:
  // Lembre-se que as iniciais dos meses sao:
  std::string months[] = {"Jan", "Fev", "Mar", "Abr", "Mai", "Jun", "Jul", "Ago", "Set", "Out", "Nov","Dez"};

  int i = 0; 
  for(i; str[i] != '/'; i++);

  std::string month;
  for(++i; str[i] != '/'; i++) 
    month += str[i];

  std::cout << months[std::stoi(month)-1] << std::endl;
}