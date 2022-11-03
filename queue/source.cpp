#include <iostream>
#include "lqueue.h"
#include "arrqueue.h"

void lqtest();
void arrtest();

int main() {
	lqtest();
	arrtest();
	return 0;
}

void lqtest() {
	LQueue<int> q1;
	std::cout << "Is empty: " << std::boolalpha << q1.isEmpty() << std::endl;
	q1.enqueue(2);
	q1.enqueue(3);
	q1.enqueue(4);
	std::cout << "Is empty: " << std::boolalpha << q1.isEmpty() << std::endl;
	std::cout << "\nFront is: " << q1.front() << std::endl;
	q1.dequeue();
	std::cout << "Front is: " << q1.front() << std::endl;
	q1.enqueue(5);
	q1.enqueue(7);
	q1.dequeue();
	//q1.print();
	q1.enqueue(8);
	std::cout << "Front is: " << q1.front() << std::endl;
}

void arrtest() {
	ArrQueue<int> q(5);

	std::cout << "q is empty: " << std::boolalpha << q.isEmpty() << std::endl;
	int x;
	std::cout << "\nEnter the numbers you want to add to the queue:" << std::endl;
	while (std::cin >> x) {
		q.enqueue(x);
	}

	std::cout << "q is empty: " << std::boolalpha << q.isEmpty() << std::endl;

	std::cout << "Front is: " << q.front() << std::endl;
	q.dequeue();

	std::cout << "Front is: " << q.front() << std::endl;
	q.dequeue();

	q.enqueue(8);
	q.enqueue(7);

	q.print();
	std::cout<<q.isFull();
	system("pause");
}