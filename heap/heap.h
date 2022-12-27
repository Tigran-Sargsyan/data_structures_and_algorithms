#pragma once

#include <vector>
#include <assert.h>

template <typename T>
class Heap
{
public:
	void insert(const T&);
	void remove();

	T get() const;
	bool empty() const;
	void print() const;

private:
	int leftIndex(int i) const;
	int rightIndex(int i) const;
	int parentIndex(int i) const;

	void heapifyUp(int i);
	void heapifyDown(int i);

private:
	std::vector<T> m_data;
};

template <typename T>
void Heap<T>::insert(const T& val)
{
	m_data.push_back(val);
	heapifyUp(m_data.size() - 1);
}

template <typename T>
void Heap<T>::remove()
{
	assert(!empty());

	m_data[0] = m_data.back();
	m_data.pop_back();
	heapifyDown(0);
}

template <typename T>
T Heap<T>::get() const
{
	assert(!empty());

	return m_data[0];
}

template <typename T>
bool Heap<T>::empty() const
{
	return m_data.empty();
}

template <typename T>
int Heap<T>::leftIndex(int i) const
{
	const int index = 2 * i + 1;
	return index < m_data.size() ? index : -1;
}

template <typename T>
int Heap<T>::rightIndex(int i) const
{
	const int index = 2 * i + 2;
	return index < m_data.size() ? index : -1;
}

template <typename T>
int Heap<T>::parentIndex(int i) const
{
	return i != 0 ? (i - 1) / 2 : -1;
}

template <typename T>
void Heap<T>::heapifyUp(int i)
{
	if (i == -1)
		return;

	const int par = parentIndex(i);
	if (par == -1)
		return;

	if (m_data[i] > m_data[par]) {
		std::swap(m_data[i], m_data[par]);
		heapifyUp(par);
	}
}

template <typename T>
void Heap<T>::heapifyDown(int i)
{
	if (i == -1)
		return;

	int maxChildIndex = leftIndex(i);
	if (maxChildIndex == -1)
		return;

	const int rIndex = rightIndex(i);
	if (rIndex != -1 && m_data[rIndex] > m_data[maxChildIndex])
	{
		maxChildIndex = rIndex;
	}

	if (m_data[i] < m_data[maxChildIndex]) {
		std::swap(m_data[i], m_data[maxChildIndex]);
		heapifyDown(maxChildIndex);
	}
}

template <typename T>
void Heap<T>::print() const
{
	typename std::vector<T>::const_iterator it = m_data.begin();
	const typename std::vector<T>::const_iterator endIt = m_data.end();
	for (; it != endIt; ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
