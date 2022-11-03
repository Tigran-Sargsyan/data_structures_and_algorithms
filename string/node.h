#pragma once

struct Node {
	Node(char x, Node* ptr1 = nullptr, Node* ptr2 = nullptr)
		: data(x)
		, prev(ptr1)
		, next(ptr2)
	{}

	char data;
	Node* next;
	Node* prev;
};