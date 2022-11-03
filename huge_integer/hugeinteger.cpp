#include <iostream>
#include <math.h>

#include "hugeinteger.h"

HugeInteger::HugeInteger(int num) {
	int k;
	while (num) {
		k = num % 10;
		insertAtHead(k);
		num /= 10;
	}
}

void HugeInteger::insertAtHead(int k) {
	if (head_ == nullptr) {
		tail_ =	head_ = new Node(k, head_);
	}
	else {
		head_ = new Node(k, head_);
		if (head_->next != nullptr) {
			head_->next->prev = head_;
		}
	}
	++size_;
}

int HugeInteger::mySize(int size) const {
	if (size_ < size) {
		int num = 0;
		int power = size_ - 1;
		Node* ptr = head_;
		while (ptr) {
			num += ptr->data * pow(10, power--);
			ptr = ptr->next;
		}
		return num;
	}
	return -1;
}

HugeInteger HugeInteger::operator+(const HugeInteger& other) const {
	HugeInteger res;
	Node* ptr1 = tail_;
	Node* ptr2 = other.tail_;

	int k = 0;
	int sum;

	while (ptr1 && ptr2) {
		sum = ptr1->data + ptr2->data + k;
		res.insertAtHead(sum % 10);
		k = sum / 10;
		ptr1 = ptr1->prev;
		ptr2 = ptr2->prev;
	}

	if (ptr1) {
		while (ptr1) {
			sum = ptr1->data + k;
			res.insertAtHead(sum % 10);
			k = sum / 10;
			ptr1 = ptr1->prev;
		}
	}

	if (ptr2) {
		while (ptr2) {
			sum = ptr2->data + k;
			res.insertAtHead(sum % 10);
			k = sum / 10;
			ptr2 = ptr2->prev;
		}
	}

	if (k == 1) {
		res.insertAtHead(k);
	}
	return res;
}

HugeInteger& HugeInteger::operator=(const HugeInteger& other) {
	if (&other == this) {
		return *this;
	}
	head_ = other.head_;
	tail_ = other.tail_;
	size_ = other.size_;
	return *this;
}

void HugeInteger::print() const {
	Node* ptr = head_;
	while (ptr) {
		std::cout << ptr->data;
		ptr = ptr->next;
	}
	std::cout << std::endl;
}