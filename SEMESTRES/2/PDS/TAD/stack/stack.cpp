#include <iostream>
#include "stack.h"

using namespace std;

Stack::Stack() {
  arr = new int[100];
  max_size = 99;
  top = -1;
}

// Destructor
Stack::~Stack() {
  delete[] arr;
}

void Stack::push(int val) {
  if(top == max_size)
    cout << "Stack is full!" << endl;
  else
    arr[++top] = val;
}

void Stack::pop() {
  if(top == -1)
    cout << "Stack is empty!" << endl;
  else
    top--;
}

int Stack::get_top() {
  if(top != -1)
    return arr[top];
  else
    return -1;
}

bool Stack::empty() {
  return (top == -1);
}
