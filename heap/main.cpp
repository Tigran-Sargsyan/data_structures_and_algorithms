#include <iostream>

#include "heap.h"

int main()
{
	Heap<int> h;
	h.insert(10);
	h.insert(7);
	h.insert(14);
	h.insert(55);
	h.insert(9);
	h.insert(1);
	h.insert(3);

	std::cout << h.get() << std::endl;

	h.remove();

	std::cout << h.get() << std::endl;

	h.print();

	std::cout << "heap sort...\n";
	while (!h.empty()) {
		std::cout << h.get() << ' ';
		h.remove();
	}
	std::cout << std::endl;

	system("pause");
	return 0;
}