#pragma once

template <typename T>
class Queue {
public:
	Queue() {}
	virtual ~Queue() {}
	
	virtual void enqueue(const T&) = 0;
	virtual void dequeue() = 0;
	virtual T front() const = 0;
	virtual bool isEmpty() const = 0;
	virtual void clear() = 0;
	virtual void print() = 0;
};
