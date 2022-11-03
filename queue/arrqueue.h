#pragma once
#include "queue.h"
#include <assert.h>

template <typename T>
class ArrQueue : public Queue<T> {
public:
	ArrQueue(int);
	~ArrQueue();

	virtual void enqueue(const T&);
	virtual void dequeue();
	virtual T front() const;
	virtual bool isEmpty() const;
	virtual int size() const;
	virtual void clear();
	virtual void print();
	bool isFull() const;

private:
	int maxSize_;
	int* arr_;
	int front_;
	int rear_;
};

template <typename T>
ArrQueue<T>::ArrQueue(int size)
	: maxSize_(size + 1)
	, arr_(new T[maxSize_])
	, rear_(0)
	, front_(1)
{}

template <typename T>
ArrQueue<T>::~ArrQueue() {
	delete[] arr_;
}

template <typename T>
void ArrQueue<T>::enqueue(const T& data) {
	assert(!isFull());
	rear_ = (rear_ + 1) % maxSize_;
	arr_[rear_] = data;
}

template <typename T>
void ArrQueue<T>::dequeue() {
	assert(!isEmpty());
	front_ = (front_ + 1) % maxSize_;
}

template <typename T>
T ArrQueue<T>::front() const {
	assert(!isEmpty());
	return arr_[front_];
}

template <typename T>
int ArrQueue<T>::size() const {
	return (rear_ - front_ + 1 + maxSize_) % maxSize_;
}

template <typename T>
bool ArrQueue<T>::isEmpty() const {
	return size() == 0;
}

template <typename T>
bool ArrQueue<T>::isFull() const {
	return ((rear_ + 2) % maxSize_) == front_;
}

template <typename T>
void ArrQueue<T>::clear() {
	rear_ = 0;
	front_ = 1;
}

template <typename T>
void ArrQueue<T>::print() {
	while (!isEmpty()) {
		std::cout <<front() << " ";
		dequeue();
	}
}
