/* file_name : stack.h
 * author_name : Smitkumar Contractor
 * contact : smitcontractor@gmail.com
 * brief : preforms class stack
 */
#ifndef stackH_H
#define stackH_H

#include <iostream>

using std::cout;
using std::endl;

const int SIZE = 10;

class stackH {
public:
  /* function name : pushh
   * arguments : int
   * brief : pushes element on the stack
   * retruns : void
   */
  void pushh(int number) {
    if (top == SIZE - 1) {
      cout << "stackH overflow" << endl;
      return;
    }
    stackH[++top] = number;
  }
  /* function name : popp
   * arguments : none
   * brief : pops the top out of the stack
   * retruns : poped element
   */
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
