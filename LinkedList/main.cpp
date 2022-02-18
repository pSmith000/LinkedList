#include <iostream>
#include "List.h"

void main()
{
	//Creates two new lists
	List<int> list = List<int>();
	List<int> listTwo;

	//Tests adding several items to list in different ways and sorts them
	list.pushBack(10);
	list.pushFront(21);
	list.insert(20, 1);
	list.insert(50, -1);
	list.insert(40, 5);
	list.sort();

	//Inserts into list two, but then sets list two equal to list one
	listTwo.insert(60, 1);
	listTwo.sort();
	listTwo = list;

	//For the length of the list
	for (Iterator<int> iter = list.begin(); iter != list.end(); ++iter)
	{
		//If it contains 10, print success
		if (*iter == 10)
		{
			std::cout << "success" << std::endl;
		}
	}

	//Print the two lists
	listTwo.print();
	list.print();

}