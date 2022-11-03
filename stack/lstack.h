#pragma once
#include "node.h"
#include "stack.h"
#include <assert.h>

template <typename T>
class LStack : public Stack <T>
{
public:
	LStack();
	virtual ~LStack();

	virtual void pop();
	virtual void push(const T& data);
	virtual T top() const;
	virtual bool empty() const;
	virtual void clear();
	virtual void print();

private:
	Node<T>* top_;
	int size_;
};

template <typename T>
LStack<T>::LStack()
	: top_(nullptr)
	,size_(0)
{}

template <typename T>
LStack<T>::~LStack() {
	clear();
}

template <typename T>
void LStack<T>::pop() {
	if (!empty()) {
		Node<T>* tmp = top_;
		top_ = top_->next;
		delete tmp;
		--size_;
	}
}

template <typename T>
void LStack<T>::push(const T& data) {
	top_ = new Node<T>(data, top_);
	++size_;
}

template <typename T>
T LStack<T>::top() const {
	assert(!empty());
	return top_->data;
}

template <typename T>
bool LStack<T>::empty() const {
	return top_ == nullptr;
}

template <typename T>
void LStack<T>::clear() {
	while (!empty()) {
		pop();
	}
}

template <typename T>
void LStack<T>::print() {
	while (size_ > 0) {
		std::cout << top_->data<<' ';
		--size_;
		top_ = top_->next;
	}
}