#include "jogo_da_vida.h"
#include <iostream>
#include <vector>

using namespace std;

JogoDaVida::JogoDaVida(int l, int c) {
  for(int i = 0; i < l; i++) {
    vector<bool> row;
    for(int j = 0; j < c; j++) row.push_back(false);
    vivas_.push_back(row);
  }
}

bool JogoDaVida::viva(int i, int j) {
  return vivas_[i][j];
}

void JogoDaVida::Matar(int i, int j) {
  if(i >= 0 && i < linhas() && j >= 0 && j < colunas())
    vivas_[i][j] = false;
  else
    throw ExcecaoCelulaInvalida{i, j};
}

void JogoDaVida::Reviver(int i, int j) {
  if(i >= 0 && i < linhas() && j >= 0 && j < colunas())
    vivas_[i][j] = true;
  else
    throw ExcecaoCelulaInvalida{i, j};
}

void JogoDaVida::ExecutarProximaIteracao() {
  vector<vector<bool>> nextIt (linhas(), vector<bool> (colunas(), 0));

  for(int i = 0; i < linhas(); i++) {
    for(int j = 0; j < colunas(); j++) {
      int lives = NumeroDeVizinhasVivas(i, j);
      if(lives < 2 || lives > 3) nextIt[i][j] = false;
      else if(!viva(i, j) && lives == 3) nextIt[i][j] = true;
      else nextIt[i][j] = vivas_[i][j];
    }
  }

  for(int i = 0; i < linhas(); i++) for(int j = 0; j < colunas(); j++)
    vivas_[i][j] = nextIt[i][j];
}

int JogoDaVida::NumeroDeVizinhasVivas(int x, int y) {
  int movL[8] = {1, -1, 0, 0, 1, 1, -1, -1};
  int movC[8] = {0, 0, 1, -1, 1, -1, 1, -1};

  int count = 0;
  for(int i = 0; i < 8; i++) {
    int nx = x + movL[i];
    int ny = y + movC[i];

    if(nx < 0)
      nx += linhas();
    if(ny < 0)
      ny += colunas();
    if(nx >= linhas())
      nx %= linhas();
    if(ny >= colunas())
      ny %= colunas();

    if(viva(nx, ny)) count++; 
  }

  return count;
}