#ifndef B_TREE
#define B_TREE
#include <iostream>
#include <queue>

using std::queue;

class Btree {
public:
  Btree() {
    root_ = NULL;
  }
  void insert(int number);
  void delete_(int number);
  void show();
  void bfs();
  void my_bfs();
private:
  class Node {
  public:
    Node(int number, Node* left, Node* right) {
      left_ = left;
      right_ = right;
      number_ = number;
    }
    Node* left_;
    Node* right_;
    int number_;
  };
  Node* root_;
  int find_min(Node* root);
  void insert(int number, Node*& curr_root);
  void delete_(int number, Node*& curr_root);
  void show(Node*& curr_root);
};

#endif
