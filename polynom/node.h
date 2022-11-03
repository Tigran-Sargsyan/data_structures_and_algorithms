#pragma once

struct Node {
	Node(int coefficient = 0, int power = 0, Node* ptr = nullptr) 
		: coeff(coefficient)
		, pow(power)
		, next(ptr)
	{}

	int coeff;
	int pow;
	Node* next;
};