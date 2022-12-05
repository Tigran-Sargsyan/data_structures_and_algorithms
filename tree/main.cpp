#include "tree.h"
#include "Node.h"
//#include "BSTree.h"

#include <iostream>

int main()
{
	Node<char>* j = new Node<char>('j');
	Node<char>* i = new Node<char>('i');
	Node<char>* g = new Node<char>('g', j, i);
	Node<char>* h = new Node<char>('h');
	Node<char>* d = new Node<char>('d', g, h);
	Node<char>* b = new Node<char>('b', nullptr, d);

	Node<char>* e = new Node<char>('e');
	Node<char>* f = new Node<char>('f');
	Node<char>* c = new Node<char>('c', e, f);

	Node<char>* a = new Node<char>('a', b, c);

	Tree<char> t(a);

	/*BSTree<int> t;
	t.insert(4);
	t.insert(2);
	t.insert(3);
	t.insert(1);
	t.insert(4);*/

	std::cout << "Preorder:  ";
	t.preorder();

	std::cout << "\nPreorderI: ";
	t.preorderI();

	std::cout << "\nInorder:  ";
	t.inorder();

	std::cout << "\nInorderI: ";
	t.inorderI();

	std::cout << "\nPostorder:  ";
	t.postorder();

	std::cout << "\nPostorderI: ";
	t.postorderI();

	std::cout << "\n\nlevelorder: ";
	t.levelorder();

	std::cout << "\nzigzag: ";
	t.zigzag();
	std::cout << std::endl;

	std::cout << "\nWidth: " << t.width() << std::endl;
	std::cout << "Height: " << t.height() << std::endl;
	std::cout << "\ncountOfLeaves: " << t.countOfLeaves() << std::endl;
	std::cout << "countOfNodes: " << t.countOfNodes() << std::endl;
	std::cout << "countOfInternalNodes: " << t.countOfInternalNodes() << std::endl;

	t.clear();
	std::cout << "\nPostorder after clear:  ";
	t.postorder();

	system("pause");

	return 0;
}