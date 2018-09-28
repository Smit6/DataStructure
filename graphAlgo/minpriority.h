/**
 * @file minpriority.h
 *
 * Declaration of the MinPriorityQ class.
 * it will also declare constructor of Element class and vector
 * of pointer to elemnts
 *
 * @author Smitkumar Contractor
 * @date 03/25/18
 */

// header guards
#ifndef CSCI_311_MINPRIORITY_H
#define CSCI_311_MINPRIORITY_H

// includes
#include <vector>
#include <iostream>

// using statements
using std::string;
using std::vector;

// class declaration
class MinPriorityQ {
  public:
    void insert(string, int);
    void decreaseKey(string, int);
    string extractMin();
    bool isMember(string);
    void print();
  private:
    // declaration of Element class
    class Element {
      public:
        Element(string, int);
        string myId;
        int myKey;
    };
    void buildMinHeap();
    void minHeapify(int);
    int parent(int);
    int left(int);
    int right(int);
    // vector of Element pointer
    vector<Element*> myQ;
};

#endif
