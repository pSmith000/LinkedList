#pragma once
#include "Iterator.h"
#include <iostream>

template<typename T>
class List
{
public:
	/// <summary>
	/// The constructor for the list that sets the base variables
	/// </summary>
	List();

	/// <summary>
	/// The constructor that sets the list equal to another list
	/// </summary>
	/// <param name="other">the other list to set this list equal to</param>
	List(const List<T>& other);

	/// <summary>
	/// The deconstructor for the list
	/// </summary>
	~List();

	/// <summary>
	/// deletes all nodes in the list
	/// </summary>
	void destroy();

	/// <summary>
	/// returns an iterator pointing to the first node in the list
	/// </summary>
	Iterator<T> begin() const;

	/// <summary>
	/// returns the next item after the last node in the list
	/// </summary>
	Iterator<T> end() const;

	/// <summary>
	/// checks to see if the given item is in the list
	/// </summary>
	/// <param name="object">the item to check for</param>
	/// <returns>true if the item is found</returns>
	bool contains(const T object) const;

	/// <summary>
	/// adds a new node to the beginning of the list
	/// </summary>
	/// <param name="value">the value to put at the front of the list</param>
	void pushFront(const T& value);

	/// <summary>
	/// adds a new node to the end of the list
	/// </summary>
	/// <param name="value">the value to put at the end of the list</param>
	void pushBack(const T& value);

	/// <summary>
	/// adds a new node at the given index
	/// </summary>
	/// <param name="value">The value to add</param>
	/// <param name="index">the index at which to add the value at</param>
	/// <returns>true if the item was inserted</returns>
	bool insert(const T& value, int index);

	/// <summary>
	/// removes the first node with the given value
	/// </summary>
	/// <param name="value">the value to remove</param>
	/// <returns>true if the item was removed</returns>
	bool remove(const T& value);

	/// <summary>
	/// prints the values for all the nodes
	/// </summary>
	void print() const;

	/// <summary>
	/// set the default values for the first node pointer, the last node pointer, and the node count
	/// </summary>
	void initialize();

	/// <summary>
	/// returns whether or not the list has any nodes in it
	/// </summary>
	/// <returns>true if the list is empty</returns>
	bool isEmpty() const;

	/// <summary>
	/// sets the given iterator to point to a node at the given index
	/// </summary>
	/// <param name="iter"></param>
	/// <param name="index"></param>
	/// <returns></returns>
	bool getData(Iterator<T>& iter, int index);

	/// <summary>
	/// returns the amount of nodes in the list
	/// </summary>
	int getLength() const;

	/// <summary>
	/// The overload of the equals operator
	/// </summary>
	/// <param name="otherList">sets the other list to this list</param>
	/// <returns>this list that was set equal tot he other list</returns>
	const List<T>& operator =(const List<T>& otherList);

	/// <summary>
	/// Sorts the list from lowest to highest
	/// </summary>
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
	//Sets a temp node for iterating
	Node<T>* otherCurrentNode = other.m_first;

	//for the length of the other list
	for (int i = 0; i < other.m_nodeCount; i++)
	{
		//insert the nodes into the new list at the specific index
		insert(otherCurrentNode->data, i);
		otherCurrentNode = otherCurrentNode->next;
	}
}

template<typename T>
inline List<T>::~List()
{
	//Destroys the list
	destroy();
}

template<typename T>
inline void List<T>::destroy()
{
	//Sets current node and next node for iterating
	Node<T>* currentNode = m_first;
	Node<T>* nextNode;

	//for the length of the list
	for (int i = 0; i < getLength(); i++)
	{
		//deletes each node and moves on to the next
		nextNode = currentNode->next;
		delete currentNode;
		m_nodeCount--;
		currentNode = nextNode;
	}

	//re-initializes the list
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
	//if tje last node is null
	if (m_last == nullptr)
		//return the iterator pointing at the null node
		return Iterator<T>(m_last);
	//Returns the last node in the list
	return Iterator<T>(m_last->next);
}

template<typename T>
inline bool List<T>::contains(const T object) const
{
	bool objectFound = false;
	//Sets current node for iterating
	Node<T>* currentNode = m_first;

	//for the length of the list
	for (int i = 0; i < getLength(); i++)
	{
		//if the current node is the object we need to find
		if (currentNode->data == object)
		{
			//set that the object has been found
			objectFound = true;
		}
		//set the current node to be its next node
		currentNode = currentNode->next;
	}
	//return the object found bool
	return objectFound;
}

template<typename T>
inline void List<T>::pushFront(const T& value)
{
	//Creates a new node with the given value
	Node<T>* newNode = new Node<T>(value);

	//if the first node is null
	if (m_first != nullptr)
	{
		//set the new nodes next to be the first
		newNode->next = m_first;
	}
	
	//Sets the new node as the first node
	m_first = newNode;

	//if the newnode next is not null
	//meaning that this is not the root
	if (newNode->next != nullptr)
	{
		//set the next's previous to be the new node
		newNode->next->previous = newNode;
	}
	else
	{
		//set the last node to be the new node
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

	//if the last nodes previous is not null
	//meaning that it is not the root
	if (m_last->previous != nullptr)
	{
		//set the new nodes previous next to be the new node
		newNode->previous->next = newNode;
	}
	else
		//set the first node to be the new node
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
	//if the first and last nodes are null and the node count is 0 then return true
	if (m_first == nullptr && m_last == nullptr && m_nodeCount == 0)
		return true;
	else
		return false;
}

template<typename T>
inline bool List<T>::getData(Iterator<T>& iter, int index)
{
	//if the index is outside of the bounds return false
	if (index <= 0 || index > getLength())
		return false;

	//set the iter to look at the first node
	iter = begin();

	//for the number of the index
	for (int i = 0; i < index; i++)
	{
		//cycle through until the iter is pointing at the correct node
		++iter;
	}

	return true;
}

template<typename T>
inline int List<T>::getLength() const
{
	//return the number of nodes
	return m_nodeCount;
}

template<typename T>
inline const List<T>& List<T>::operator=(const List<T>& otherList)
{
	//destroy the list and create a node for iterating
	destroy();
	Node<T>* otherCurrentNode = otherList.m_first;

	//for the length of the other list
	for (int i = 0; i < otherList.m_nodeCount; i++)
	{
		//insert the nodes at the same points in the new list as the other list and iterate
		insert(otherCurrentNode->data, i);
		otherCurrentNode = otherCurrentNode->next;
	}

	//return the derederence of this list
	return *this;
}

template<typename T>
inline void List<T>::sort()
{
	//Set a current node and temp node to iterate
	Node<T>* currentNode = m_first;
	Node<T>* tempNode = new Node<T> ();

	//for the number of nodes minus 1
	for (int i = 0; i < m_nodeCount - 1; i++)
	{
		//set the current node back to the first one on every loop
		currentNode = m_first;

		for (int j = 0; j < m_nodeCount - 1; j++)
		{
			//if the currents next is less than the current
			if (currentNode->next->data < currentNode->data)
			{
				//Swap the nodes data
				tempNode->data = currentNode->next->data;
				currentNode->next->data = currentNode->data;
				currentNode->data = tempNode->data;
			}
			//and go to the next node
			currentNode = currentNode->next;
		}
	}
}
