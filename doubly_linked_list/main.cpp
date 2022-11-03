#include <iostream>
#include "dllist.h"

int main() {
	DLList<int> l;
	l.insert(0, 1);
	l.insert(1, 3);
	l.insert(2, 4);
	l.insert(1, 2);
	l.print();
	int pos = l.find(1);
	std::cout << "The position of 1 is: " << pos << std::endl;
	std::cout << "The element at index " << pos <<" is: " << l.getVal(pos) << std::endl;
	l.erase(0);
	l.print();
	std::cout << "empty = " << std::boolalpha << l.empty() << std::endl;
	l.clear();
	std::cout << "empty = " << std::boolalpha << l.empty() << std::endl;
	return 0;
}