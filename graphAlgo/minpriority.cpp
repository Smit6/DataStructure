/**
 * @file minpriority.cpp   implements funcitons for MinPriorityQ and
 * Element class.
 *
 * @brief
 * it will initialize private variable of Hash class. after
 * that it will also
 * perform fuctions of class MinPriorityQ and Element. it will perform
 * constructors of calss Element, insert, decreaseKey, extractMin,
 * isMember, buildMinHeap, minHeapify, parent, left, right.
 *
 * @author Smitkumar Contractor
 * @date 3/18/2018
 */

// includes
#include "minpriority.h"

// using statements
using std::cerr;
using std::endl;
using std::cout;

// definitions of class MinPriorityQ and Element

/**
 * MinPriorityQ::Element::Element
 *
 * implemets constructor of class Element
 * it will initialize variables myId and myKey
 *
 * @param string (id of the element), int (key of the element)
 * @returns none.
 */
MinPriorityQ::Element::Element(string id, int key) {
  myId = id;
  myKey = key;
}

/**
 * MinPriorityQ::insert
 *
 * insert an Element in our MinPriorityQ
 * It will create a new Element and add information from prameters
 * It will push element into the MinPriorityQ and after that it
 * will call decrease key function which will make it MinPriorityQ
 *
 * @param string (id of the element), int (key of the element)
 * @returns none (void)
 */
void MinPriorityQ::insert(string id, int key) {
  Element *element = new Element(id, key);
  myQ.push_back(element);
  decreaseKey(id, key);
}

/**
 * MinPriorityQ::decreaseKey
 *
 * it will decrease key of a particular element in MinPriorityQ
 * it will start by decreasing key, after decreasing key it will
 * perform buildMinHeap, which will mantain min heap of elements
 * with the help of minHeapify
 *
 * @param string (id of the element), int (key of the element)
 * @returns none (void)
 */
void MinPriorityQ::decreaseKey(string id, int key) {
  unsigned int i = 0;
  for (i = 0; i < myQ.size(); i++) {
    if (id == myQ[i]->myId) {
      id = "idExistSmit";
      break;
    }
  }
  if (id != "idExistSmit")
    return;
  if (key > myQ[i]->myKey) {
    // cerr << "new key is greater than current key." << endl;
  }
  myQ[i]->myKey = key;
  while (i > 0 && myQ[parent(i)]->myKey > myQ[i]->myKey) {
    Element *temp = myQ[i];
    myQ[i] = myQ[parent(i)];
    myQ[parent(i)] = temp;
    i = parent(i);
  }
  // buildMinHeap();
}

/**
 * MinPriorityQ::extractMin
 *
 * it will extract the node with the lowest index
 * so, basically it will erase or extract the very first element
 * of our MinPriorityQ
 *
 * @param none
 * @returns string (the string of element which we extracted).
 */
string MinPriorityQ::extractMin() {
  if (myQ.size() <= 0)
    return "empty";
  string minimum = myQ[0]->myId;
  delete myQ[0];
  myQ.erase(myQ.begin());
  minHeapify(0);
  return minimum;
}

/**
 * MinPriorityQ::isMember
 *
 * isMember will check if element with the given id exist
 * it will go through each element in our MinPriorityQ and
 * compare it with the string given in parameter
 *
 * @param string (Id to find element in our max MinPriorityQ)
 * @returns boolean (true if id exitst else false).
 */
bool MinPriorityQ::isMember(string id) {
  for (unsigned int i = 0; i < myQ.size(); i++) {
    if (myQ[i]->myId == id)
      return true;
  }
  return false;
}

/**
 * MinPriorityQ::buildMinHeap
 *
 * buildMinHeap will build min heap represetation of MinPriorityQ
 * with help of minHeapify, it will call minHeapify (size / 2)
 * times, to create a min heap represetation of MinPriorityQ
 *
 * @param none
 * @returns none (void)
 */
void MinPriorityQ::buildMinHeap() {
  for (int i = ((myQ.size() - 1) / 2); i > -1; i--)
    minHeapify(i);
}

/**
 * MinPriorityQ::minHeapify
 *
 * method of arranging elements in MinPriorityQ
 * minHeapify will arrange elements in MinPriorityQ where value of
 * the parent is lesser than that of it's childrends.
 *
 * @param int (i stands for index of the element)
 * @returns none (void)
 */
void MinPriorityQ::minHeapify(int i) {
  int minimum;
  int l = left(i);
  int r = right(i);
  if (l < (int) myQ.size() && myQ[l]->myKey < myQ[i]->myKey)
    minimum = l;
  else
    minimum = i;
  if (r < (int) myQ.size() && myQ[r]->myKey < myQ[minimum]->myKey)
    minimum = r;
  if (minimum != i) {
    Element *temp = myQ[i];
    myQ[i] = myQ[minimum];
    myQ[minimum] = temp;
    minHeapify(minimum);
  }
}

/**
 * MinPriorityQ::parent
 *
 * parent (this funciton) will return index of parent element
 * it will take index from parameter and after that it will
 * find index of it's parent element.
 *
 * @param int (i stands for index of the element)
 * @returns int (index of parent element)
 */
int MinPriorityQ::parent(int i) {
  return ((i - 1) / 2);
}

/**
 * MinPriorityQ::left
 *
 * left (this funciton) will return index of left element
 * it will take index of parent element from parameter and after
 * that it will find index of it's left element and return it.
 *
 * @param int (i stands for index of the parent element)
 * @returns int (index of left element)
 */
int MinPriorityQ::left(int i) {
  return (2 * i);
}

/**
 * MinPriorityQ::right
 *
 * right (this funciton) will return index of right element
 * it will take index of parent element from parameter and after
 * that it will find index of it's right element and return it.
 *
 * @param int (i stands for index of the parent element)
 * @returns int (index of right element)
 */
int MinPriorityQ::right(int i) {
  return ((2 * i) + 1);
}

/**
 * MinPriorityQ::print
 *
 * print (this funciton) will print element of MinPriorityQ
 * it will loop through all elements of the MinPriorityQ and
 * print it to standard out
 *
 * @param none
 * @returns none
 */
void MinPriorityQ::print() {
  cout << "------------------" << endl;
  for (int i = 0; i < (int) myQ.size(); i++) {
    cout << i << ". id = " << myQ[i]->myId
      << "\tkey = " << myQ[i]->myKey << endl;
  }
  cout << "Q size = " << myQ.size() << endl;
  cout << "------------------" << endl;
}
