#pragma once

template <typename T>
struct Node {
	Node(const T& x, Node<T>* ptr)
		:data(x)
		,next(ptr)
	{}
	T data;
	Node<T>* next;
};