#pragma once

#include "node.h"

template <typename T>
class List {
public:
	List() {}
	virtual ~List() {}

	virtual void insert(int, const T&) = 0;
	virtual void erase(int) = 0;
	virtual T getVal(int) const = 0;
	virtual int find(const T&) const = 0;
	virtual bool empty() const = 0;
	virtual void clear() = 0;
	virtual int size() const = 0;
	virtual bool full() const = 0;
};