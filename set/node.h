#pragma once

struct Node{
	Node(const int& x, Node* ptr = nullptr)
		: data(x)
		, next(ptr)
	{}

	int data;
	Node* next;
};