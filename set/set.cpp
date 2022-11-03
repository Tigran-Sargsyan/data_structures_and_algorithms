#include "set.h"

#include <iostream>

Set::Set(int* a, int n) 
	:m_head(nullptr)
{
	for (int i = 0; i < n; ++i) {
		insert(a[i]);
	}
}

void Set::insert(int value) {
	Node* ptr = m_head;
	Node* ptrPrev = nullptr;

	while (ptr && ptr->data < value) {
		ptrPrev = ptr;
		ptr = ptr->next;
	}

	if (ptr && ptr->data == value) {
		std::cout << "Skipping: " << value << std::endl;
		return;
	}

	if (ptrPrev == nullptr) {
		m_head = new Node(value, m_head);
	}
	else {
		ptrPrev->next = new Node(value, ptrPrev->next);
	}
	
}

bool Set::contains(int value) const {
	Node* ptr = m_head;
	while (ptr && ptr->data < value) {
		ptr = ptr->next;
	}

	return ptr && ptr->data == value;
}

void Set::print() const {
	Node* ptr = m_head;
	while (ptr) {
		std::cout << ptr->data << " ";
		ptr = ptr->next;
	}
	std::cout << std::endl;
}

Set Set::merge_easy(const Set& other) {
	Node* ptr = other.m_head;
	while (ptr) {
		if (!contains(ptr->data)) {
			insert(ptr->data);
		}
		ptr = ptr->next;
	}
	return *this;
}

Set Set::merge(const Set& other) const {
	Set res;

	Node* ptr1 = m_head;
	Node* ptr2 = other.m_head;
	Node* tail = res.m_head; // nullptr

	while (ptr1 && ptr2) {
		int dataToInsert = ptr1->data;
		if (ptr1->data < ptr2->data) {
			ptr1 = ptr1->next;
		}
		else if (ptr2->data < ptr1->data) {
			dataToInsert = ptr2->data;
			ptr2 = ptr2->next;
		}
		else {
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}

		if (tail == nullptr) {
			tail = res.m_head = new Node(dataToInsert);
		}
		else {
			tail = tail->next = new Node(dataToInsert);
		}
	}

	while (ptr1) {
		tail = tail->next = new Node(ptr1->data);
		ptr1 = ptr1->next;
	}
	while (ptr2) {
		tail = tail->next = new Node(ptr2->data);
		ptr2 = ptr2->next;
	}

	return res;
}