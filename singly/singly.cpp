#include "singly.h"

using std::cout;
using std::endl;

void LinkedList::insert (int number) {
  Node* node = new Node(number);
	if (head_ == NULL) {
		head_ = node;
		node->next_ = NULL;
		return;
	} else {
		Node* temp = head_;
		if (temp->number_ >= number) {
		node->next_ = head_;
    head_ = node;
    return;
		}
		Node* temp_prev = head_;
		temp = head_->next_;
		while (temp != NULL && temp->number_ < number) {
			temp = temp->next_;
			temp_prev = temp_prev->next_;
		}
		if (temp == NULL) {
			temp_prev->next_ = node;
			node->next_ = NULL;
			return;
		}
		temp_prev->next_ = node;
  	node->next_ = temp;
	}
}

void LinkedList::delete_(int number) {
	if (head_ == NULL)
		return;
	Node* temp = head_;
	if (head_->number_ == number) {
		head_= head_ ->next_;
		delete temp;
		return;
	} else {
		Node* temp_prev = head_;
		Node* temp = head_->next_;
		while (temp != NULL && temp->number_ != number) {
			temp = temp->next_;
			temp_prev = temp_prev->next_;
		}
		if (temp == NULL)
			return;
		Node* ptr = temp;
		temp = temp->next_;
		temp_prev->next_ = temp;
		delete ptr;
	}
}

void LinkedList::display() {
  Node* temp = head_;
  while (temp != NULL) {
    cout << temp->number_ << endl;
    temp = temp->next_;
  }
}
