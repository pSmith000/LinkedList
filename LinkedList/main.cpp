#include <iostream>
#include "List.h"

void main()
{
	List<int> list = List<int>();

	list.pushFront(1);
	list.pushBack(12);
	list.print();
}