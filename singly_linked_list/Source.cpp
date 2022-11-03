#include <iostream>
#include "node.h"
#include "linked_list.h"

int main() {
	LinkedList<int> lst;
	lst.insertAt(3, 0);
	lst.insertAt(5, 1);
	lst.insertAt(7, 2);
	lst.insertAt(6, 2);
	lst.insertAt(4, 3);  
	// 3,5,6,4,7
	lst.deleteAt(2); 
	lst.deleteAt(0);
	lst.print();
	std::cout << "\nEmpty = " << lst.isEmpty() << std::endl;
	lst.clear();
	std::cout << "\nEmpty = " << lst.isEmpty() << std::endl;
	return 0;
}