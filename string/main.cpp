#include "string.h"
#include <iostream>

int main() {
	const int n = 4;
	char a[n] = {'h','e','y'};
	String s(a, n);
	s.print();
	s.insert(' ');
	s.insert('y');
	s.insert('o');
	s.insert('u');
	s.print();
	const int m = 6;
	char b[m] = "hello";
	String s2(b, m);
	s2.print();
	std::cout << s.index('y') << std::endl;
	//s2 = s;
	std::cout << s.countWords() << std::endl;
	s2.insert(' ');
	s2.insert(',');
	s2.insert(' ');
	s2.insert('h');
	s2.insert('i');
	s2.insert(' ');
	std::cout << s2.countWords() << std::endl;
	return 0;
}