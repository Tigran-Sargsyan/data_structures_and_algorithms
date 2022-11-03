#pragma once
#include "node.h"

class Polynom {
public:
	Polynom()
		: head_(nullptr)
		, size_(0)
	{}
	Polynom(int*, int*, int);
	int freeTerm() const; 
	int countValue(int) const;
	Polynom operator-(Polynom) const;
	Polynom& operator=(Polynom);
	void print() const;

private:
	void insert(int, int);

private:
	Node* head_;
	int size_;
};
