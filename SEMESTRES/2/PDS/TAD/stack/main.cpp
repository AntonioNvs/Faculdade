#include <iostream>
#include "stack.h"

using namespace std;

int main() {
  Stack p;

  cout << "Stack is empty? " << p.empty() << endl;
  p.push(10);
  cout << "Top element: " << p.get_top() << endl;

  return 0;
}