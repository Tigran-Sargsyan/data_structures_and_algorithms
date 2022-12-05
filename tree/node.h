#pragma once

template <typename T>
struct Node 
{
	Node(const T& d, Node<T>* l = nullptr, Node<T>* r = nullptr)
		: data(d)
		, left(l)
		, right(r)
	{}

	T data;
	Node<T>* left;
	Node<T>* right;
};