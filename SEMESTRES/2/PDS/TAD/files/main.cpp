#include <iostream>
#include <fstream>
#include <cstdlib>

#include "file.hpp"

using namespace std;

int main() {
  char option;
  string line;

  File src = File("text.txt");

  while(true) {
    cout << endl;
    cout << "O que deseja fazer?" << endl;
    cin >> option;

    // Escrever algo no arquivo
    switch (option)
    {
    case 'w':
      getline(cin, line);
      src.insert(line);
      break;
    case 'r':
      for(auto row : src.read())
        cout << row << endl;
      break;
    case 'c':
      src.clean();
      break;
    case 'n':
      cout << "Número de linhas: " << src.nrows() << endl;
      break;
    default:
      return 0;
    }

    cout << endl;
    cout << "Digite qualquer coisa para passar" << endl;
    cin >> line;
    
    system("cls");
  }
}