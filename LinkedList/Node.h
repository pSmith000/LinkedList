#pragma once

template<typename T>
class Node
{
public:
	/// <summary>
	/// The node constructor that sets the variables to base values
	/// </summary>
	Node();

	/// <summary>
	/// The constructor that sets the data to the given value
	/// </summary>
	/// <param name="value">the value to set the data to</param>
	Node(T value);

	//The nodes after this node
	Node<T>* next;
	//The node before this node
	Node<T>* previous;
	//The data this node holds
	T data;

};

template<typename T>
inline Node<T>::Node()
{
	//sets the values to base stats
	next = nullptr;
	previous = nullptr;
	data = 0;
}

template<typename T>
inline Node<T>::Node(T value)
{
	//sets the data to be equal to thye value
	data = value;
}
