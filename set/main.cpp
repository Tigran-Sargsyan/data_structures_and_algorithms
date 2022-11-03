#include <iostream>
#include "set.h"

void test();

int main() {
	const int n = 6;
	int arr[n] = { 1,10,2,8,2,5 };
	Set s(arr,n);
	s.print();
	s.insert(3);
	s.print();
	s.insert(6);
	s.print();
	std::cout << std::boolalpha << s.contains(2) << std::endl;
	const int m = 4;
	int b[m] = { 1,4,4,7 };
	Set s2(b, 4);
	s.merge_easy(s2);
	s.print();
	Set s3 = s.merge(s2); // ** = is not manually overloaded,which is not good.
	s3.print();
	test();

	return 0;
}

void test() {
	int a[] = { 1, 4, 71, 3 };

	Set s(a, 4);
	s.print();

	s.insert(-1);
	s.print();

	s.insert(7);
	s.print();

	s.insert(7);
	s.print();

	s.insert(-1);
	s.print();

	s.insert(100);
	s.print();

	std::cout << "set contains 8: " << std::boolalpha << s.contains(8) << std::endl;
	std::cout << "set contains -9: " << std::boolalpha << s.contains(-9) << std::endl;
	std::cout << "set contains 100: " << std::boolalpha << s.contains(100) << std::endl;
	std::cout << "set contains 4: " << std::boolalpha << s.contains(4) << std::endl;

	int b[] = { -1, 4, 6, 20, 30, 40 };

	Set s2(b, 6);

	std::cout << "\n\n========== set 1 ==========\n";
	s.print();

	std::cout << "\n\n========== set 2 ==========\n";
	s2.print();

	Set s3 = s.merge(s2); // !!!!!!!!!!!!!!!!!!

	std::cout << "\n\n========== merged set ==========\n";
	s3.print();
}