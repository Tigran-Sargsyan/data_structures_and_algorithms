#pragma once
#include "list.h"
#include <assert.h>

template <typename T>
class DLList : public List<T> {
public:
	DLList();
	virtual ~DLList();

	virtual void insert(int, const T&);
	virtual void erase(int);
	virtual T getVal(int) const;
	virtual int find(const T&) const;
	virtual bool empty() const;
	virtual void clear();
	virtual int size() const;
	virtual bool full() const;
	void print() const;

private:
	bool isValidPosition(int) const;
	Node<T>* runTo(int) const;
	//void print() const;

private:
	int size_;
	Node<T>* head_;
};

template <typename T>
DLList<T>::DLList()
	: size_(0)
	, head_(nullptr)
{}

template <typename T>
DLList<T>::~DLList() {
	clear();
}

template <typename T>
void DLList<T>::insert(int pos, const T& x) {
	assert(pos >= 0 && pos <= size_);
	if (pos == 0) {
		head_ = new Node<T>(x, head_);
		if (head_->next != nullptr) {
			head_->next->prev = head_;
		}
	}
	else {
		Node<T>* tmp = runTo(pos - 1);
		Node<T>* new_node = new Node<T>(x, tmp->next, tmp);
		tmp->next = new_node;
		if (new_node->next != nullptr) {
			new_node->next->prev = new_node;
		}
	}
	++size_;
}

template <typename T>
Node<T>* DLList<T>::runTo(int pos) const {
	assert(isValidPosition(pos));
	Node<T>* tmp = head_;
	for (int i = 0; i < pos; ++i) {
		tmp = tmp->next;
	}
	return tmp;
}

template <typename T>
bool DLList<T>::isValidPosition(int pos) const {
	// for getVal and Deletion
	return pos >= 0 && pos < size_;
}

template <typename T>
int DLList<T>::find(const T& a) const
{
	Node<T>* tmp = head_;
	for (int i = 0; i < size_; ++i) {
		if (tmp->data == a) {
			return i;
		}
		tmp = tmp->next;
	}
	return -1;
}

template <typename T>
T DLList<T>::getVal(int pos) const {
	Node<T>* tmp = runTo(pos);
	return tmp->data;
}

template <typename T>
void DLList<T>::erase(int pos) {
	assert(isValidPosition(pos));
	assert(!empty());
	if (pos == 0) {
		if (head_->next == nullptr) {
			delete head_;
			head_ = nullptr;
		}
		else {
			head_ = head_->next;
			delete head_->prev;
			head_->prev = nullptr;
		}
	}
	else {
		Node<T>* tmp = runTo(pos);
		tmp->prev->next = tmp->next;
		if (tmp->next != nullptr) {
			tmp->next->prev = tmp->prev;
		}
		delete tmp;
	}
	--size_;
}

template <typename T>
bool DLList<T>::empty() const {
	return head_ == nullptr;
}

template <typename T>
void DLList<T>::clear() {
	while (!empty()) {
		erase(0);
	}
}

template <typename T>
int DLList<T>::size() const {
	return size_;
}

template <typename T>
bool DLList<T>::full() const {
	return false;
}

template <typename T>
void DLList<T>::print() const {
	Node<T>* tmp = head_;
	while (tmp != nullptr) {
		std::cout << tmp->data << " ";
		tmp = tmp->next;
	}
	std::cout << std::endl;
}
