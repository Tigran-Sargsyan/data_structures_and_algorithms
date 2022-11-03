#pragma once
#include "node.h"

class String {
public:
	String()  // Default Constructor
		: head_(nullptr)
		, tail_(nullptr)
		, size_(0)
	{}
	String(char*, int);
	~String(); 
	//String(const String&); // Copy Constructor
	String& operator=(const String);
	void insert(char);
	void print() const;
	int index(char) const;
	int countWords() const;

private:
	Node* head_;
	Node* tail_;
	int size_;
};