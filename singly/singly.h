#ifndef SINGLY_LL
#define SINGLY_LL

#include <iostream>

using std::cout;
using std::endl;

// class LinkedList {
// public:
//   LinkedList() {
//     head_ = NULL;
//   }
//   void insert(int);
//   void display();
//   void delete_(int);
// private:
//   class Node {
//   public:
//     Node (int number) {
//       number_ = number;
//     }
//     Node* next_;
//     int number_;
//   };
//   Node* head_;
// };
class LinkedList {
public:
  LinkedList() {
    head_ = NULL;
  }
  void display() {
    Node* temp = head_;
    while (temp != NULL) {
      cout << temp->number_ << endl;
      temp = temp->next_;
    }
  }
  void insert(int number) {
    Node* node = new Node(number, NULL);
    if (head_ == NULL || head_->number_ > number) {
      node->next_ = head_;
      head_ = node;
      return;
    }
    Node* temp_prev = head_;
    Node* temp = head_->next_;
    while (temp != NULL && temp->number_ <= number) {
      temp_prev = temp_prev->next_;
      temp = temp->next_;
    }
    temp_prev->next_ = node;
    node->next_ = temp;
  }
  void delete_(int number) {
    if (head_ == NULL)
      return;
    if (head_->number_ == number) {
      Node* temp = head_;
      head_ = head_->next_;
      delete temp;
      return;
    }
    Node* temp = head_->next_;
    Node* temp_prev = head_;
    while (temp != NULL && temp->number_ != number) {
      temp = temp->next_;
      temp_prev = temp_prev->next_;
    }
    if (temp != NULL) {
      Node* rem = temp;
      temp = temp->next_;
      temp_prev->next_ = temp;
      delete rem;
    }
  }
private:
  class Node {
  public:
    Node(int number, Node* next) {
      number_ = number;
      next_ = next;
    }
    int number_;
    Node* next_;
  };
  Node* head_;
};

#endif /* SINGLY_LL*/
