#include <iostream>
#include "List.h"

void main()
{
	List<int> list = List<int>();

	list.pushBack(2);
	list.pushFront(1);
	list.pushFront(12);
	list.pushBack(15);
	list.pushBack(14);
	list.insert(200, 3);
	list.insert(149, 1);
	list.remove(1);
	list.sort();
	list.print();

	std::cout << " " << std::endl;

	list.destroy();
	list.insert(10, 0);
	list.insert(45, 1);
	list.pushBack(47);
	list.print();

	std::cout << " " << std::endl;

	List<int> listTwo = List<int>();
	listTwo = list;

	listTwo.print();

}