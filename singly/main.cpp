#include "singly.h"

using std::cout;
using std::endl;

int main() {
  LinkedList ll;
  ll.insert(5);
  cout << "------" << endl;
  ll.display();
  ll.insert(2);
  cout << "------" << endl;
  ll.display();
  ll.insert(10);
  cout << "------" << endl;
  ll.display();
  ll.insert(1);
  cout << "------" << endl;
  ll.display();
  ll.insert(10);
  cout << "------" << endl;
  ll.display();
  ll.insert(4);
  cout << "------" << endl;
  ll.display();
  ll.insert(9);
  cout << "------" << endl;
  ll.display();
  ll.delete_(1);
  cout << "------" << endl;
  ll.display();
  ll.delete_(5);
  cout << "------" << endl;
  ll.display();
  ll.delete_(4);
  cout << "------" << endl;
  ll.display();
  ll.insert(3);
  cout << "------" << endl;
  ll.display();
  ll.insert(6);
  cout << "------" << endl;
  ll.display();
  ll.insert(7);
  cout << "------" << endl;
  ll.display();
  ll.delete_(10);
  cout << "------" << endl;
  ll.display();
  ll.delete_(10);
  cout << "------" << endl;
  ll.display();
  ll.delete_(7);
  cout << "------" << endl;
  ll.display();
  ll.delete_(9);
  cout << "------" << endl;
  ll.display();
}
