/* file_name : stack.cpp
 * author_name : Smitkumar Contractor
 * contact : smitcontractor@gmail.com
 * brief : perform call to procedurs of class stackH
 */
#include "stack.h"

#include <iostream>

using std::cout;
using std::endl;

int main() {
  stackH s;
  s.pushh(10);
  cout << s.popp() << endl;
  cout << s.popp() << endl;
  return 0;
}
