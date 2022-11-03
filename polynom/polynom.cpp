#include "polynom.h"

#include <iostream>
#include <assert.h>
#include <math.h>

Polynom::Polynom(int* val_arr, int* pow_arr, int size) {
	//assert(sizeof(val_arr) == sizeof(pow_arr));
	for (int i = 0; i < size; ++i) {
		insert(val_arr[i], pow_arr[i]);
	}
}

void Polynom::insert(int coeff, int power) {
	Node* ptr_prev = nullptr;
	Node* ptr = head_;
	
	if (head_ == nullptr) {
		head_ = new Node(coeff, power);
		return;
	}

	while (ptr && ptr->pow > power) {
		ptr_prev = ptr;
		ptr = ptr->next;
	}

	if (ptr_prev) {
		ptr_prev->next = new Node(coeff, power, ptr);
	}

	else {
		head_ = new Node(coeff, power, ptr);
	}
	++size_;
}

int Polynom::countValue(int x) const {
	Node* ptr = head_;
	int res = 0;
	while (ptr) {
		res += ptr->coeff * pow(x, ptr->pow);
		ptr = ptr->next;
	}
	return res;
} 

int Polynom::freeTerm() const {
	Node* ptr = head_;
	while (ptr) {
		if (ptr->pow == 0) {
			return ptr->coeff;
		}
		ptr = ptr->next;
	}
	return 0;
}

Polynom Polynom::operator-(Polynom p2) const {
	Polynom res;
	Node* ptr1 = head_;
	Node* ptr2 = p2.head_;
	while (ptr1 && ptr2) {
		if (ptr1->pow > ptr2->pow) {
			res.insert(ptr1->coeff, ptr1->pow);
			ptr1 = ptr1->next;
		}
		else if (ptr1->pow < ptr2->pow) {
			res.insert(ptr2->coeff, ptr2->pow);
			ptr2 = ptr2->next;
		}
		else {
			int new_coeff = ptr1->coeff - ptr2->coeff;
			res.insert(new_coeff, ptr1->pow);
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}
	}
	
	while (ptr1) {
		res.insert(ptr1->coeff, ptr1->pow);
		ptr1 = ptr1->next;
	}

	while (ptr2) {
		res.insert(ptr2->coeff, ptr2->pow);
		ptr2 = ptr2->next;
	}
	return res;
}

Polynom& Polynom::operator=(Polynom p2) {
	if (&p2 == this) {
		return *this;
	}
	head_ = p2.head_;
	size_ = p2.size_;
	return *this;
}

void Polynom::print() const {
	Node* ptr = head_;
	while (ptr) {
		std::cout << ptr->coeff << " * x ^ " << ptr->pow << std::endl;
		ptr = ptr->next;
	}
	std::cout << std::endl;
}