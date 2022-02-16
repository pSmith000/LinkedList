#include <iostream>
#include "List.h"

void main()
{
	List<int> list = List<int>();
	List<int> listTwo;

	list.sort();
	list.pushBack(10);
	list.pushFront(21);
	list.insert(20, 1);
	list.insert(50, -1);
	list.insert(40, 5);
	list.sort();
	list.initialize();
	listTwo.insert(60, 1);
	listTwo.sort();
	listTwo = list;

	for (Iterator<int> iter = list.begin(); iter != list.end(); ++iter)
	{
		if (*iter == 10)
		{
			std::cout << "success" << std::endl;
		}
	}

	listTwo.print();
	list.print();

}