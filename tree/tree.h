#pragma once

#include "node.h"

#include <iostream>
#include <stack>
#include <queue>

template <typename T>
void setNodeValue(Node<T>* ptr)
{
	if (!ptr->left && !ptr->right)
		ptr->data = 1;
	else {
		ptr->data = 0;
		if (ptr->left)
			ptr->data += ptr->left->data;
		if (ptr->right)
			ptr->data += ptr->right->data;
	}
}

template <typename T>
void printNodeValue(Node<T>* ptr)
{
	std::cout << ptr->data << ' ';
}

template <typename T>
class Tree
{
public:
	Tree(Node<T>* root = nullptr);
	~Tree();

	void preorder() const;
	void inorder() const;
	void postorder() const;

	void preorderI() const;
	void inorderI() const;
	void postorderI() const;

	void levelorder() const;
	void zigzag() const;

	int width() const;
	int height() const;
	int countOfLeaves() const;
	int countOfNodes() const;

	void setCountOfLeaves();
	void setCountOfLeavesI();

	void clear();

	void postorderWithVisitor(void(*visit)(Node<T>* p));

private:
	void preorderHelper(Node<T>*) const;
	void inorderHelper(Node<T>*) const;
	void postorderHelper(Node<T>*) const;
	void clearHelper(Node<T>*);
	int heightHelper(Node<T>*) const;

	int countOfLeavesHelper(Node<T>*) const;
	int countOfNodesHelper(Node<T>*) const;

	void setCountOfLeavesHelper(Node<T>*);

protected:
	Node<T>* m_root;
};

template <typename T>
Tree<T>::Tree(Node<T>* root)
	: m_root(root)
{}

template <typename T>
Tree<T>::~Tree()
{
	clear();
}

template <typename T>
void Tree<T>::preorder() const
{
	preorderHelper(m_root);
}

template <typename T>
void Tree<T>::inorder() const
{
	inorderHelper(m_root);
}

template <typename T>
void Tree<T>::postorder() const
{
	postorderHelper(m_root);
}

template <typename T>
void Tree<T>::preorderI() const
{
	std::stack<Node<T>*> s;
	Node<T>* ptr = m_root;
	while (true) {
		while (ptr) {
			std::cout << ptr->data << " ";
			if (ptr->right) {
				s.push(ptr->right);
			}
			ptr = ptr->left;
		}

		if (s.empty()) {
			return;
		}

		ptr = s.top();
		s.pop();
	}
}

template <typename T>
void Tree<T>::inorderI() const
{
	std::stack<Node<T>*> s;
	Node<T>* ptr = m_root;

	while (true)
	{
		while (ptr)
		{
			s.push(ptr);
			ptr = ptr->left;
		}

		if (s.empty())
			return;

		ptr = s.top();
		s.pop();
		std::cout << ptr->data << " ";
		ptr = ptr->right;
	}
}

template <typename T>
void Tree<T>::postorderI() const
{
	std::stack<Node<T>*> s;
	Node<T>* ptr = m_root;
	while (true) {
		while (ptr) {
			if (ptr->right) {
				s.push(ptr->right);
			}
			s.push(ptr);
			ptr = ptr->left;
		}

		if (s.empty()) {
			return;
		}

		ptr = s.top();
		s.pop();

		if (ptr->right && !s.empty() && s.top() == ptr->right) {
			s.pop();
			s.push(ptr);
			ptr = ptr->right;
		}
		else {
			std::cout << ptr->data << " ";
			ptr = nullptr;
		}
	}
}

template <typename T>
void Tree<T>::levelorder() const
{
	std::queue<Node<T>*> q;
	q.push(m_root);

	while (!q.empty()) {
		Node<T>* tmp = q.front();
		q.pop();
		std::cout << tmp->data << " ";

		if (tmp->left)
			q.push(tmp->left);

		if (tmp->right)
			q.push(tmp->right);
	}
}

template <typename T>
void Tree<T>::zigzag() const
{
	int count = 0;
	unsigned int width = 0;
	std::queue<Node<T>*> q;
	std::stack<T> s;
	q.push(m_root);
	while (!q.empty()) {
		width = q.size();
		if (count % 2 == 0) {
			for (int i = 0; i < width; ++i) {
				Node<T>* tmp = q.front();

				if (tmp->left)
					q.push(tmp->left);

				if (tmp->right)
					q.push(tmp->right);

				s.push(tmp->data);
				q.pop();
			}
			for (int i = 0; i < width; ++i) {
				std::cout << s.top() << " ";
				s.pop();
			}
		}
		else {
			for (int i = 0; i < width; ++i) {
				Node<T>* tmp = q.front();
				std::cout << tmp->data << " ";
				if (tmp->left)
					q.push(tmp->left);

				if (tmp->right)
					q.push(tmp->right);

				q.pop();
			}
		}
		++count;
	}
}

template <typename T>
int Tree<T>::width() const
{
	int w = 1;
	std::queue<Node<T>*> q;
	q.push(m_root);
	while (!q.empty()) {
		unsigned int count = q.size();
		if (count > w)
			w = count;

		for (int i = 0; i < count; ++i) {
			Node<T>* tmp = q.front();
			q.pop();

			if (tmp->left)
				q.push(tmp->left);

			if (tmp->right)
				q.push(tmp->right);
		}
	}
	return w;
}

template <typename T>
void Tree<T>::clear()
{
	clearHelper(m_root);
	m_root = nullptr;
}

template <typename T>
void Tree<T>::preorderHelper(Node<T>* p) const
{
	if (p == nullptr)
	{
		return;
	}

	std::cout << p->data << " ";
	preorderHelper(p->left);
	preorderHelper(p->right);
}

template <typename T>
void Tree<T>::inorderHelper(Node<T>* p) const
{
	if (p == nullptr)
	{
		return;
	}

	inorderHelper(p->left);
	std::cout << p->data << " ";
	inorderHelper(p->right);
}

template <typename T>
void Tree<T>::postorderHelper(Node<T>* p) const
{
	if (p == nullptr)
	{
		return;
	}

	postorderHelper(p->left);
	postorderHelper(p->right);
	std::cout << p->data << " ";
}

template <typename T>
void Tree<T>::clearHelper(Node<T>* p)
{
	if (p == nullptr)
	{
		return;
	}

	clearHelper(p->left);
	clearHelper(p->right);
	delete p;
	p = nullptr;
}

template <typename T>
int Tree<T>::countOfLeaves() const
{
	return countOfLeavesHelper(m_root);
}

template <typename T>
int Tree<T>::countOfLeavesHelper(Node<T>* p) const
{
	if (p == nullptr)
	{ 
		return 0;
	}
	if (!p->left && !p->right)
	{
		return 1;
	}

	return countOfLeavesHelper(p->left) + countOfLeavesHelper(p->right);
}

template <typename T>
int Tree<T>::countOfNodes() const
{
	return countOfNodesHelper(m_root);
}

template <typename T>
int Tree<T>::countOfNodesHelper(Node<T>* p) const
{
	if (p == nullptr)
	{
		return 0;
	}

	return 1 + countOfNodesHelper(p->left) + countOfNodesHelper(p->right);
}

template <typename T>
int Tree<T>::height() const
{
	return heightHelper(m_root) - 1;
}

template <typename T>
int Tree<T>::heightHelper(Node<T>* p) const
{
	if (p == nullptr) {
		return 0;
	}
	return 1 + std::max(heightHelper(p->left), heightHelper(p->right));
}

template <typename T>
void Tree<T>::setCountOfLeaves()
{
	setCountOfLeavesHelper(m_root);
}

template <typename T>
void Tree<T>::setCountOfLeavesHelper(Node<T>* ptr)
{
	if (ptr == nullptr)
		return;
	if (ptr->left == nullptr && ptr->right == nullptr) {
		ptr->data = 1;
		return;
	}

	setCountOfLeavesHelper(ptr->left);
	setCountOfLeavesHelper(ptr->right);

	ptr->data = 0;
	if (ptr->left)
		ptr->data += ptr->left->data;
	if (ptr->right)
		ptr->data += ptr->right->data;
}

template <typename T>
void Tree<T>::setCountOfLeavesI()
{
	postorderWithVisitor(setNodeValue<T>);

	/*
	std::stack<Node<T>*> s;
	Node<T>* ptr = m_root;
	while (true) {
		while (ptr) {
			if (ptr->right) {
				s.push(ptr->right);
			}
			s.push(ptr);
			ptr = ptr->left;
		}

		if (s.empty()) {
			return;
		}

		ptr = s.top();
		s.pop();

		if (ptr->right && !s.empty() && s.top() == ptr->right) {
			s.pop();
			s.push(ptr);
			ptr = ptr->right;
		}
		else {
			if (!ptr->left && !ptr->right)
				ptr->data = 1;
			else {
				ptr->data = 0;
				if (ptr->left)
					ptr->data += ptr->left->data;
				if (ptr->right)
					ptr->data += ptr->right->data;
			}

			ptr = nullptr;
		}
	}
	*/
}

template <typename T>
void Tree<T>::postorderWithVisitor(void (*visit)(Node<T>* p))
{
	std::stack<Node<T>*> s;
	Node<T>* ptr = m_root;
	while (true) {
		while (ptr) {
			if (ptr->right) {
				s.push(ptr->right);
			}
			s.push(ptr);
			ptr = ptr->left;
		}

		if (s.empty()) {
			return;
		}

		ptr = s.top();
		s.pop();

		if (ptr->right && !s.empty() && s.top() == ptr->right) {
			s.pop();
			s.push(ptr);
			ptr = ptr->right;
		}
		else {
			visit(ptr);

			ptr = nullptr;
		}
	}
}