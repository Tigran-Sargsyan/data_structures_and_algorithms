#include <iostream>
#include "polynom.h"

int main() {

	std::cout << "---- p1 ----" << std::endl;
	
	const int n = 4;			  // Number of not null coefficients of the polynom.
	int coeff[n] = {1,2,4,3};  // Array for holding coefficients.
	int pow[n] = {0,1,3,5}; // Array for holding powers of corresponding coefficients.
	Polynom p1(coeff, pow, n); 
	p1.print();
	
	int x = 2;
	std::cout << "The value at the point " << x <<" is: " << p1.countValue(x) << std::endl;
	std::cout << "Free term is: " << p1.freeTerm() << std::endl;

	
	std::cout << "\n---- p2 ----" << std::endl;
	
	const int m = 3;
	int coeff1[m] = {3,9,8};
	int pow1[m] = {2,3,5};
	Polynom p2(coeff1, pow1, m);
	p2.print();
	
	std::cout << "The value at the point " << x << " is: " << p2.countValue(x) << std::endl;
	std::cout << "Free term is: " << p2.freeTerm() << std::endl;

	
	std::cout << "\n---- p3 = p1 - p2 ----" << std::endl;
	
	Polynom p3;
	p3 = p1 - p2;   
	p3.print();
	
	return 0;
}