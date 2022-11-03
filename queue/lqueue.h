#pragma once
#include "queue.h"
#include "node.h"
#include <assert.h>

template <typename T>
class LQueue : public Queue<T> {
public:
	LQueue();
	virtual ~LQueue();
	
	virtual void enqueue(const T&);
	virtual void dequeue();
	virtual T front()const;
	virtual bool isEmpty()const;
	virtual void clear();
	virtual void print();

private:
	Node<T>* front_;
	Node<T>* rear_;
	int size_;
};

template <typename T>
LQueue<T>::LQueue()
	: size_(0)
	, front_(nullptr)
	, rear_(nullptr)
{
	//rear_ = new Node<T>(0, nullptr);
}

template <typename T>
LQueue<T>::~LQueue() {
	clear();
}

template <typename T>
void LQueue<T>::enqueue(const T& x){
	if (rear_ == nullptr) {  // If queue is empty (size_ == 0).
		front_ = rear_ = new Node<T>(x, nullptr);
	}
	else {
		rear_->next = new Node<T>(x, nullptr);
		rear_ = rear_->next;
	}
	++size_;
}

template <typename T>
void LQueue<T>::dequeue() {
	if (!isEmpty()) {
		Node<T>* tmp = front_;
		front_ = front_->next;
		delete tmp;
	}
	--size_;
}

template <typename T>
T LQueue<T>::front() const {
	assert(!isEmpty());
	return front_->data;
}

template <typename T>
bool LQueue<T>::isEmpty() const {
	return size_ == 0;
}

template <typename T>
void LQueue<T>::clear() {
	while (!isEmpty()) {
		dequeue();
	}
}

template <typename T>
void LQueue<T>::print() {
	Node<T>* current = front_;
	while (current != nullptr) {
		std::cout << current->data << ' ';
		current = current->next;
	}
	std::cout << std::endl;
}
