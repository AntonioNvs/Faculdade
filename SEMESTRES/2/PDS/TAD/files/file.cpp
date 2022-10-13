#include "file.hpp"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

File::File(string filename) {
  this->filename = filename;
}

fstream File::open(char mode) {
  fstream src;
  src.open(filename, (mode == 'w' ? ios::out : ios::in));
  return src;
}

vector<string> File::read() {
  vector<string> lines;
  fstream src = this->open('r');

  string line;
  while(getline(src, line)) {
    lines.push_back(line);
  }

  src.close();

  return lines;
}

void File::insert(string sentence) {
  vector<string> lines = read();
  fstream src = this->open('w');

  lines.push_back(sentence);

  for(auto line : lines)
    src << line << '\n';

  src.close();
}

void File::clean() {
  fstream src = this->open('w');
  src.close();
}

int File::nrows() {
  return read().size();
}