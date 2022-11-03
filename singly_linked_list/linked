#pragma once
#include "node.h"
#include <assert.h>

template <typename T>
class LinkedList {
public:
	LinkedList();
	//~LinkedList();

	void insertAfter(const T&, Node<T>*);
	void insertAt(const T&, int);
	void deleteAt(int);
	void deleteAfter(Node<T>*);
	bool isEmpty()const;
	void clear();
	void print();

private:
	Node<T>* head_;
	int size_;
};

template <typename T>
LinkedList<T>::LinkedList()
	:head_(nullptr)
	,size_(0) 
	{}

/*template <typename T>
LinkedList<T>::~LinkedList(){
	clear();
}*/

template <typename T>
void LinkedList<T>::insertAfter(const T& x, Node<T>* ptr) {
	ptr->next = new Node<T>(x, ptr->next);
	++size_;
}

template <typename T>
void LinkedList<T>::insertAt(const T& x,int pos) {
	if (pos < 0 || pos > size_) {
		std::cout << "You entered a wrong index:" << std::endl;
	}
	else if (pos == 0) {
		head_ = new Node<T>(x, head_);
		++size_;
	}
	else {
		Node<T>* tmp = head_;
		for (int i = 0; i < pos - 1; ++i) {
			tmp = tmp->next;
		}
		insertAfter(x, tmp);
	}
}

template <typename T>
void LinkedList<T>::deleteAfter(Node<T>* ptr) {
	Node<T>* tmp = ptr->next;
	ptr->next = (ptr->next)->next;
	delete tmp;
	--size_;
}

template <typename T>
void LinkedList<T>::deleteAt(int pos) {
	if (pos < 0 || pos >= size_) {
		std::cout << "You entered a wrong index:" << std::endl;
	}
	else if (pos == 0) {
		assert(!isEmpty());
		Node<T>* tmp = head_;
		head_ = head_->next;
		delete tmp;
		--size_;
	}
	else {
		Node<T>* tmp = head_;
		for (int i = 0; i < pos - 1; ++i) {
			tmp = tmp->next;
		}
		deleteAfter(tmp);
	}
}

template <typename T>
bool LinkedList<T>::isEmpty() const {
	return head_ == nullptr;
}

template <typename T>
void LinkedList<T>::clear() {
	while (!isEmpty()) {
		deleteAt(0);
	}
}

template <typename T>
void LinkedList<T>::print() {
	Node<T>* tmp = head_;
	while (tmp != nullptr) {
		std::cout << tmp->data << " ";
		tmp = tmp->next;
	}
}
