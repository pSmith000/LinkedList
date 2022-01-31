#pragma once
#include "Iterator.h"
#include <iostream>

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

template<typename T>
inline List<T>::List()
{
	//creates an empty list
	m_first = nullptr;
	m_last = nullptr;
	m_nodeCount = 0;
}

template<typename T>
inline List<T>::List(const List<T>& other)
{
	//Creates a list with the other lists variables
	m_first = other.m_first;
	m_last = other.m_last;
	m_nodeCount = other.getLength();
}

template<typename T>
inline List<T>::~List()
{
}

template<typename T>
inline void List<T>::destroy()
{
}

template<typename T>
inline Iterator<T> List<T>::begin() const
{
	//Return the first node in the list
	return Iterator<T>(m_first);
}

template<typename T>
inline Iterator<T> List<T>::end() const
{
	//Returns the last node in the list
	return Iterator<T>(m_last);
}

template<typename T>
inline bool List<T>::contains(const T object) const
{
	return false;
}

template<typename T>
inline void List<T>::pushFront(const T& value)
{
	//Creates a new node with the given value
	Node<T>* newNode = new Node<T>(value);

	//Sets the first nodes previous to be the new node
	m_first->previous = newNode;
	//Sets the new nodes next to be the first node
	newNode->next = m_first;
	//Sets the new node as the first node
	m_first = newNode;

	//Increases the node count
	m_nodeCount++;
}

template<typename T>
inline void List<T>::pushBack(const T& value)
{
	//Creates a new node with the given value
	Node<T>* newNode = new Node<T>(value);

	//Sets the last nodes next to be the new node
	m_last->next = newNode;
	//Sets the new nodes previous to be the last node
	newNode->previous = m_last;
	//Sets the new node to be the last
	m_last = newNode;

	//Increases the node count
	m_nodeCount++;
}

template<typename T>
inline bool List<T>::insert(const T& value, int index)
{
	//Create a bool to return
	bool nodeInserted = false;

	//Two temp variables to use to insert the new node
	Node<T>* nodeToInsert = new Node<T>(value);
	Node<T>* currentNode = m_first;

	//If the index is 0
	if (index == 0)
	{
		//Make a new node at the front
		pushFront(value);
		nodeInserted = true;
	}
		
	//If the index is at the end of the list
	if (index == getLength())
	{
		//Make a new node at the back
		pushBack(value);
		nodeInserted = true;
	}
		
	//If the index is within the bounds
	if (index > 0 && index < getLength())
	{
		//Loop through the list to get the the index
		for (int i = 0; i < index; i++)
		{
			//Setting the current node to be the next every time
			if (currentNode->next)
			{
				currentNode = currentNode->next;
			}
		}

		//Set the new nodes next and previous
		nodeToInsert->next = currentNode;
		nodeToInsert->previous = currentNode->previous;
		//Set the current nodes previous next
		currentNode->previous->next = nodeToInsert;
		//Set the current nodes previous
		currentNode->previous = nodeToInsert;

		//Increase the node count and sets the bool to be true
		m_nodeCount++;
		nodeInserted = true;
	}
	
	//Return id the node was inserted
	return nodeInserted;
}

template<typename T>
inline bool List<T>::remove(const T& value)
{
	//Create a bool to return
	bool nodeRemoved = false;

	//Two temp variables to use to insert the new node
	Node<T>* nodeToRemove = m_first;

	if (nodeToRemove->data == value)
	{

	}
}

template<typename T>
inline void List<T>::print() const
{
	for (Iterator<T> iter = begin(); iter != end(); ++iter)
	{
		std::cout << &iter << std::endl;
	}
}

template<typename T>
inline void List<T>::initialize()
{
	m_first = nullptr;
	m_last = nullptr;
	m_nodeCount = 0;
}

template<typename T>
inline bool List<T>::isEmpty() const
{
	if (m_first == nullptr && m_last == nullptr && m_nodeCount == 0)
		return true;
	else
		return false;
}

template<typename T>
inline bool List<T>::getData(Iterator<T>& iter, int index)
{
	return false;
}

template<typename T>
inline int List<T>::getLength() const
{
	return m_nodeCount;
}

template<typename T>
inline const List<T>& List<T>::operator=(const List<T>& otherList)
{
	// TODO: insert return statement here
}

template<typename T>
inline void List<T>::sort()
{
}
