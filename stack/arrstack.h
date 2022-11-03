#pragma once
#include "stack.h"
#include <assert.h>


template <typename T>
class ArrStack : public Stack <T>{
public:
	ArrStack(int);
	virtual ~ArrStack();
	virtual void push(const T&);
	virtual void pop();
	virtual T top() const;
	virtual bool empty() const;
	virtual void clear();
	virtual void print();

private:
	T* arr_;
	int size_;
	int topIndex_;
};

template <typename T>
ArrStack<T>::ArrStack(int size)
	:size_(size)
	,topIndex_(0)
	,arr_(new T[size_])
{}

template <typename T>
ArrStack<T>::~ArrStack() {
	clear();
}

template <typename T>
void ArrStack<T>::push(const T &data) {
	if (topIndex_ >= size_) {
		std::cout << "The stack is full! " << std::endl;
		return;
	}
	arr_[topIndex_++] = data;
}

template <typename T>
void ArrStack<T>::pop() {
	if (!empty()) {
		topIndex_--;
	}
}

template <typename T>
T ArrStack<T>::top() const {
	assert(!empty());
	return arr_[topIndex_ - 1];
}

template <typename T>
bool ArrStack<T>::empty() const {
	return topIndex_ == 0;
}

template <typename T>
void ArrStack<T>::clear() {
	while (!empty()) {
		pop();
	}
	//delete[] arr_;  why gives an assertion error?

	topIndex_ = 0;
}

template <typename T>
void ArrStack<T>::print() {
	for (int i = topIndex_ - 1; i >= 0; --i) {
		std::cout << arr_[i] << " ";
	}
}