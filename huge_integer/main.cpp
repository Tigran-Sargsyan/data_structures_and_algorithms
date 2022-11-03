#include <iostream>
#include "hugeinteger.h"

int main() {
	HugeInteger n1(97456);
	n1.print();
	std::cout <<"Size 3: " << n1.mySize(3) << std::endl;
	std::cout <<"Size 12: " << n1.mySize(12) << std::endl;

	HugeInteger n2(23735);
	n2.print();

	HugeInteger n3;
	n3 = n1 + n2;
	n3.print();
	
	return 0;
}