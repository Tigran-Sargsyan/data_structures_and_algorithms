#pragma once
#include "node.h"

template <typename T>
class Stack
{
public:
	Stack() {}
	virtual ~Stack() {}

	virtual void pop() = 0;
	virtual void push(const T& data) = 0;
	virtual T top()const = 0;
	virtual bool empty()const = 0;
	virtual void clear() = 0;
	virtual void print() = 0;
};
