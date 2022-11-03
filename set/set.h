#pragma once
#include "node.h"

class Set {
public:
	Set() : m_head(nullptr) {};
	Set(int*, int);
	void insert(int);
	bool contains(int) const;
	Set merge_easy(const Set&);
	Set merge(const Set&) const;
	void print() const;
	
private:
	Node* m_head;

};
