#pragma once
#include "Iterator.h"

template<typename T>
class List
{
public:
	List();
	List(const List<T>& other);
	~List();

	void destroy();
	Iterator<T> begin() const;
	Iterator<T> end() const;
	bool contains(const T object) const;

	void pushFront(const T& value);
	void pushBack(const T& value);
	bool insert(const T& value, int index);
	bool remove(const T& value);

	void print() const;
	void initialize();
	bool isEmpty() const;
	bool getData(Iterator<T>& iter, int index);
	int getLength() const;

	const List<T>& operator =(const List<T>& otherList);
	void sort();

private:
	Node<T>* m_first;
	Node<T>* m_last;
	int m_nodeCount;
};

