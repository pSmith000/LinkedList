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
	Node<T>* otherCurrentNode = other.m_first;

	for (int i = 0; i < other.m_nodeCount; i++)
	{
		insert(otherCurrentNode->data, i);
		otherCurrentNode = otherCurrentNode->next;
	}
}

template<typename T>
inline List<T>::~List()
{
	destroy();
}

template<typename T>
inline void List<T>::destroy()
{
	Node<T>* currentNode = m_first;
	Node<T>* nextNode;

	for (int i = 0; i < getLength(); i++)
	{
		nextNode = currentNode->next;
		delete currentNode;
		m_nodeCount--;
		currentNode = nextNode;
	}

	initialize();
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
	return Iterator<T>(m_last->next);
}

template<typename T>
inline bool List<T>::contains(const T object) const
{
	bool objectFound = false;
	Node<T>* currentNode = m_first;

	for (int i = 0; i < getLength(); i++)
	{
		if (currentNode->data == object)
		{
			objectFound = true;
		}
		currentNode = currentNode->next;
	}

	return objectFound;
}

template<typename T>
inline void List<T>::pushFront(const T& value)
{
	//Creates a new node with the given value
	Node<T>* newNode = new Node<T>(value);

	if (m_first != nullptr)
	{
		newNode->next = m_first;
	}
	
	//Sets the new node as the first node
	m_first = newNode;

	if (newNode->next != nullptr)
	{
		newNode->next->previous = newNode;
	}
	else
	{
		m_last = newNode;
	}

	//Increases the node count
	m_nodeCount++;
}

template<typename T>
inline void List<T>::pushBack(const T& value)
{
	//Creates a new node with the given value
	Node<T>* newNode = new Node<T>(value);

	if (m_last != nullptr)
	{
		//Sets the new nodes previous to be the last node
		newNode->previous = m_last;
	}
	
	//Sets the new node to be the last
	m_last = newNode;

	if (m_last->previous != nullptr)
	{
		newNode->previous->next = newNode;
	}
	else
		m_first = newNode;
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
		return true;
	}
		
	//If the index is at the end of the list
	if (index == getLength())
	{
		//Make a new node at the back
		pushBack(value);
		nodeInserted = true;
		return true;
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

	for (int i = 0; i < m_nodeCount; i++)
	{
		//If this is the node to remove
		if (nodeToRemove->data == value)
		{
			//If this is the first node
			if (nodeToRemove->previous == nullptr)
			{
				//Set the nodes next to be the first in the list
				m_first = nodeToRemove->next;
			}
			//If this is the last node
			else if (nodeToRemove->next == nullptr)
			{
				//Set the nodes previous to be last
				m_last = nodeToRemove->previous;
			}
			//If this is a node in the middle
			else
			{
				//Set the nodes to be pointing at the right spots
				nodeToRemove->previous->next = nodeToRemove->next;
				nodeToRemove->next->previous = nodeToRemove->previous;
			}
			
			//Delete the node to remove and lower the node count by one
			delete(nodeToRemove);
			nodeRemoved = true;
			m_nodeCount--;
			break;
		}
		//If this wasn't the right node to remove, got to the next one
		else
			nodeToRemove = nodeToRemove->next;
	}
	return nodeRemoved;

}

template<typename T>
inline void List<T>::print() const
{
	//Set a new node to be the first
	Node<T>* currentNode = m_first;

	for (int i = 0; i < getLength(); i++)
	{
		//If the current node is not null
		if (currentNode != nullptr) 
		{
			//Print out the data for every node
			std::cout << currentNode->data << std::endl;
			currentNode = currentNode->next;
		}
	}
}

template<typename T>
inline void List<T>::initialize()
{
	//Sets all variables to be base
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
	if (index <= 0 || index > getLength())
		return false;

	iter = begin();

	for (int i = 0; i < index; i++)
	{
		++iter;
	}

	return true;
}

template<typename T>
inline int List<T>::getLength() const
{
	return m_nodeCount;
}

template<typename T>
inline const List<T>& List<T>::operator=(const List<T>& otherList)
{
	destroy();
	Node<T>* otherCurrentNode = otherList.m_first;

	for (int i = 0; i < otherList.m_nodeCount; i++)
	{
		insert(otherCurrentNode->data, i);
		otherCurrentNode = otherCurrentNode->next;
	}

	return *this;
}

template<typename T>
inline void List<T>::sort()
{
	Node<T>* currentNode = m_first;
	Node<T>* tempNode = new Node<T> ();

	for (int i = 0; i < m_nodeCount - 1; i++)
	{
		currentNode = m_first;

		for (int j = 0; j < m_nodeCount - 1; j++)
		{
			if (currentNode->next->data < currentNode->data)
			{
				tempNode->data = currentNode->next->data;
				currentNode->next->data = currentNode->data;
				currentNode->data = tempNode->data;
			}
			currentNode = currentNode->next;
		}
	}
}
