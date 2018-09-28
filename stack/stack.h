#ifndef stackH_H
#define stackH_H

#include <iostream>

using std::cout;
using std::endl;

const int SIZE = 10;

class stackH {
public:
  void pushh(int number) {
    if (top == SIZE - 1) {
      cout << "stackH overflow" << endl;
      return;
    }
    stackH[++top] = number;
  }
  int popp() {
    if (top == -1) {
      cout << "Nothing to delete" << endl;
      return 0;
    }
    return stackH[top--];
  }
private:
  int stackH[SIZE];
  int top = -1;
};

#endif
