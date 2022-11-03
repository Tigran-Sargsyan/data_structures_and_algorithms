#include <iostream>
#include "string.h"

String::String(char* arr, int size) {
	for (int i = 0; i < size - 1; ++i) {
		insert(arr[i]);
	}
}

/*
String::String(const String& str) {

}*/

String::~String() {
	Node* ptr = head_;
	while (ptr) {
		Node* tmp = ptr;
		ptr = ptr->next;
		delete tmp;
		--size_;
	}
}

String& String::operator=(const String str) {
	if (&str == this) {
		return *this;
	}
	head_ = str.head_;
	tail_ = str.tail_;
	size_ = str.size_;
	return *this;
}

void String::insert(char c) {
	if (head_ == nullptr) {
		tail_ = head_ = new Node(c);
	}
	else {
		tail_ = new Node(c, tail_, tail_->next);
		tail_->prev->next = tail_;
	}
	++size_;
}

void String::print() const {
	Node* ptr = head_;
	while (ptr) {
		std::cout << ptr->data << " ";
		ptr = ptr->next;
	}
	std::cout << std::endl;
}

int String::index(char c) const {
	Node* ptr = head_;
	int ind = 0;
	while (ptr) {
		if (ptr->data == c) {
			return ind;
		}
		ptr = ptr->next;
		++ind;
	}
	return -1;
}

int String::countWords() const {
	if (head_ == nullptr) {
		return 0;
	}
	int count = 0; 
	Node* ptr = head_;
	while (ptr->next) {
		if (ptr->data == ' ' && ptr->next->data != ' ') {
			++count;
		}
		ptr = ptr->next;
	}
	if (head_->data == ' ') {
		return count;
	}
	return count+1;
}
