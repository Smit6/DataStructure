#include "btree.h"

using std::cout;
using std::endl;

void Btree::insert(int number) {
  insert(number, root_);
}

void Btree::delete_(int number) {
  delete_(number, root_);
}

void Btree::show() {
  show(root_);
}

void Btree::show(Node*& curr_root) {
  if (curr_root == NULL)
    return;
  cout << curr_root->number_ << endl;
  show(curr_root->left_);
  show(curr_root->right_);
}

void Btree::insert(int number, Node*& curr_root) {
  if (curr_root == NULL) {
    curr_root = new Node(number, NULL, NULL);
    return;
  }
  if (curr_root->number_ > number)
    insert(number, curr_root->left_);
  else if (curr_root->number_ < number)
    insert(number, curr_root->right_);
}

int Btree::find_min(Node* root) {
  Node* temp = root;
  while (temp->left_ != NULL) {
    temp = temp->left_;
  }
  return temp->number_;
}


void Btree::delete_(int number, Node*& curr_root) {
  if (curr_root == NULL)
    return;
  if (curr_root->number_ == number) {
    if (curr_root->left_ == NULL && curr_root->right_ == NULL) {
      delete curr_root;
      curr_root = NULL;
    } else if (curr_root->left_ == NULL && curr_root->right_ != NULL) {
      Node* temp = curr_root;
      curr_root = curr_root->right_;
      delete temp;
    } else if (curr_root->left_ != NULL && curr_root->right_ == NULL) {
      Node* temp = curr_root;
      curr_root = curr_root->left_;
      delete temp;
    } else {
      curr_root->number_ = find_min(curr_root->right_);
      delete_(curr_root->number_, curr_root->right_);
    }
    return;
  } if (curr_root->number_ > number)
    delete_(number, curr_root->left_);
  else if (curr_root->number_ < number)
    delete_(number, curr_root->right_);
}

void Btree::bfs() {
  if (root_ == NULL)
    return;
  queue<Btree::Node*> q;
  q.push(root_);
  while (!q.empty()) {
    Node* node = q.front();
    cout << node->number_ << endl;
    q.pop();
    if (node->left_ != NULL)
      q.push(node->left_);
    if (node->right_ != NULL)
      q.push(node->right_);
  }
}

void Btree::my_bfs() {
  if (root_ == NULL)
    return;
  queue<Node*> q;
  q.push(root_);
  while (!q.empty()) {
    Node* temp = q.front();
    q.pop();
    cout << temp->number_ << endl;
    if (temp->left_ != NULL)
      q.push(temp->left_);
    if (temp->right_ != NULL)
      q.push(temp->right_);
  }
}
