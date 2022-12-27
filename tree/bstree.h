#pragma once

#include "tree.h"

template <typename T>
class BSTree : public Tree<T>
{
public:
	void insert(const T&);
	void insertI(const T&);

	void deleteVal(const T&);

	bool contains(const T&) const;
	//TODO: containsI

	T findMin() const;

private:
	Node<T>* insertHelper(Node<T>*, const T&);
	Node<T>* deleteValHelper(Node<T>*, const T&);

	const Node<T>* find(const Node<T>*, const T&) const;
	const Node<T>* findMinNode(const Node<T>*) const;
};

template <typename T>
void BSTree<T>::insert(const T& data)
{
	this->m_root = insertHelper(this->m_root, data);
}

template <typename T>
Node<T>* BSTree<T>::insertHelper(Node<T>* p, const T& data)
{
	if (!p) {
		p = new Node<T>(data); //p = new Node(data);
	}
	else if (data > p->data) {
		p->right = insertHelper(p->right, data);
	}
	else if (data < p->data) {
		p->left = insertHelper(p->left, data);
	}
	return p;
}

template <typename T>
void BSTree<T>::insertI(const T& val)
{
	if (!this->m_root) {
		this->m_root = new Node<T>(val);
		return;
	}
	Node<T>* ptr = this->m_root;
	Node<T>* par = nullptr;
	while (ptr) {
		par = ptr;
		if (val > ptr->data) {
			ptr = ptr->right;
		}
		else if (val < ptr->data) {
			ptr = ptr->left;
		}
		else {
			std::cout << val << " The value is already present on the tree" << std::endl;
			return;
		}
	}
	if (val > par->data) {
		par->right = new Node<T>(val);
	}
	else {
		par->left = new Node<T>(val);
	}
}

template <typename T>
bool BSTree<T>::contains(const T & val) const {
	return find(this->m_root, val) != nullptr;
}

template <typename T>
const Node<T>* BSTree<T>::find(const Node<T>* ptr, const T& val) const
{
	if (!ptr) {
		return nullptr;
	}

	if (val < ptr->data)
	{
		return find(ptr->left, val);
	}
	else if (val > ptr->data)
	{
		return find(ptr->right, val);
	}
	return ptr;
}

template <typename T>
T BSTree<T>::findMin() const
{
	return findMinNode(this->m_root)->data;
}

template <typename T>
const Node<T>* BSTree<T>::findMinNode(const Node<T>* ptr) const
{
	if (ptr == nullptr) {
		return nullptr;
	}

	if (ptr->left == nullptr) {
		return ptr;
	}
	return findMinNode(ptr->left);
}

template <typename T>
void BSTree<T>::deleteVal(const T& val)
{
	this->m_root = deleteValHelper(this->m_root, val);
}

template <typename T>
Node<T>* BSTree<T>::deleteValHelper(Node<T>* ptr, const T& val)
{
	if (!ptr) {
		return nullptr;
	}

	if (val < ptr->data) {
		ptr->left = deleteValHelper(ptr->left, val);
	}
	else if (val > ptr->data) {
		ptr->right = deleteValHelper(ptr->right, val);
	}
	else {
		if (!ptr->left && !ptr->right) {
			delete ptr;
			return nullptr;
		}
		if (!ptr->left) {
			Node<T>* tmp = ptr->right;
			delete ptr;
			return tmp;
		}
		if (!ptr->right) {
			Node<T>* tmp = ptr->left;
			delete ptr;
			return tmp;
		}
		const Node<T>* minP = findMinNode(ptr->right);
		ptr->data = minP->data;
		ptr->right = deleteValHelper(ptr->right, minP->data);
	}
	return ptr;
}
