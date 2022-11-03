#pragma once

template <typename T>
struct Node {
	Node(const T& x, Node<T>* ptr1 = nullptr, Node<T>* ptr2 = nullptr)
		: data(x)
		, next(ptr1)
		, prev(ptr2)
	{ }

	T data;
	Node<T>* next;
	Node<T>* prev;
};