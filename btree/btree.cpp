#include "btree.h"
#include <queue>

using std::queue;
using std::cout;
using std::endl;

void Btree::insert(int number) {
  insert(number, head_);
}

void Btree::show() {
  show(head_);
}

void Btree::delete_(int number) {
  delete_(number, head_);
}

void Btree::insert(int number, Node*& curr_head) {
  Node* node = new Node(number, NULL, NULL);
  if (curr_head == NULL) {
    curr_head = node;
    return;
  }
  if (curr_head->number_ > number) {
    insert(number, curr_head->left_);
    return;
  }
  insert(number, curr_head->right_);
}

void Btree::show(Node*& curr_head) {
  if (curr_head == NULL)
    return;
  cout << curr_head->number_ << endl;
  show(curr_head->left_);
  show(curr_head->right_);
}

void Btree::delete_(int number, Node*& curr_head) {
	if (curr_head->number_ == number) {
		if (curr_head->left_ == NULL && curr_head->right_ == NULL) {
			delete curr_head;
			curr_head = NULL;
		} else if (curr_head->left_ != NULL && curr_head->right_ == NULL) {
			Node* temp = curr_head;
			curr_head = curr_head->left_;
			delete temp;
		} else if (curr_head->left_ == NULL && curr_head->right_ != NULL) {
			Node* temp = curr_head;
			curr_head = curr_head->right_;
			delete temp;
		} else {
			curr_head->number_ = find_min(curr_head->right_);
			delete_(curr_head->number_, curr_head->right_);
		}
	} else if (curr_head->number_ > number) {
		delete_(number, curr_head->left_);
	} else if (curr_head->number_ < number) {
		delete_(number, curr_head->right_);
	} else {
		cout << "number is absent." << endl;
	}
}

int Btree::find_min(Node* curr_head) {
	Node* temp = curr_head;
	while (temp->left_ != NULL) {
		temp = temp->left_;
	}
  // cout << "number -> " << temp->number_ << endl;
	return temp->number_;
}

void Btree::bfs() {
  if (head_ == NULL)
    return;
  queue<Btree::Node*> q;
  q.push(head_);
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
	if (head_ == NULL) {
		return;
	}
	queue<Node*> q;
	q.push(head_);
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
