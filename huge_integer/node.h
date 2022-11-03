#pragma once

struct Node {
	Node(char x, Node* ptr1 = nullptr, Node* ptr2 = nullptr)
		: data(x)
		, next(ptr1)
		, prev(ptr2)
	{}

	int data;
	Node* next;
	Node* prev;
};