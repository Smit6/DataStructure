#include <iostream>

#ifndef B_TREE
#define B_TREE

class Btree {
public:
  Btree () {
    head_ = NULL;
  }
  void insert(int);
  void show();
  void delete_(int);
  void bfs();
  void my_bfs();
private:
  class Node {
  public:
    Node(int number, Node* left, Node* right) {
      number_ = number;
      left_ = left;
      right_ = right;
    }
    Node* left_;
    Node* right_;
    int number_;
  };
  void insert(int, Node*&);
  void show(Node*&);
  void delete_(int, Node*&);
  int find_min(Node* curr_head);
  Node* head_;
};

#endif /* B_TREE */
