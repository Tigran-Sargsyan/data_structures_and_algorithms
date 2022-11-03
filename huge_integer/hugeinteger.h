#pragma once
#include "node.h"

class HugeInteger {
public:
	HugeInteger()
		: head_(nullptr)
		, tail_(nullptr)
		, size_(0)
	{}
	HugeInteger(int);
	int mySize(int) const;
	HugeInteger operator+(const HugeInteger&) const;
	HugeInteger& operator=(const HugeInteger&);
	void print() const;

private:
	void insertAtHead(int);

private:
	Node* head_;
	Node* tail_;
	int size_;
};
