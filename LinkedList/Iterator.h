#pragma once
#include "Node.h"

template<typename T>
class Iterator
{
public:
	/// <summary>
	/// The constructor which sets the current node to be null
	/// </summary>
	Iterator();

	/// <summary>
	/// The constructor which sets the current node equal to the one inputed
	/// </summary>
	/// <param name="node"></param>
	Iterator(Node<T>* node);

	/// <summary>
	/// Overload of the ++ operator which sets the current node equal to the current nodes next
	/// </summary>
	/// <returns>an iterator pointing to the current node</returns>
	Iterator<T> operator++();

	/// <summary>
	/// Overload of the -- operator which sets the current node equal to the current nodes previous
	/// </summary>
	/// <returns>an iterator pointing to the current node</returns>
	Iterator<T> operator--();

	/// <summary>
	/// Checks to see if the iterators current is equal to the iters current
	/// </summary>
	/// <param name="iter">the other iterator</param>
	/// <returns>true if the currents are equal</returns>
	const bool operator==(const Iterator<T>& iter);

	/// <summary>
	/// Checks to see if the iterators current is not equal to the iters current
	/// </summary>
	/// <param name="iter">the other iterator</param>
	/// <returns>true if the currents are not equal</returns>
	const bool operator!=(const Iterator<T>& iter);

	/// <summary>
	/// Overload of the dereference operator which returns the value in the node the iterator is pointing at
	/// </summary>
	T operator *();
private:
	Node<T>* m_current;
};

template<typename T>
inline Iterator<T>::Iterator()
{
	m_current = nullptr;
}

template<typename T>
inline Iterator<T>::Iterator(Node<T>* node)
{
	m_current = node;
}

template<typename T>
inline Iterator<T> Iterator<T>::operator++()
{
	//if the current is null
	if (m_current == nullptr)
		//return the null node
		return Iterator<T>(m_current);
	else
		return Iterator<T>(m_current = m_current->next);
}

template<typename T>
inline Iterator<T> Iterator<T>::operator--()
{
	//if the currents previous is null
	if (m_current->previous == nullptr)
		//return the current node
		return Iterator<T>(m_current);
	else
		return Iterator<T>(m_current = m_current->previous);
}

template<typename T>
inline const bool Iterator<T>::operator==(const Iterator<T>& iter)
{
	//if either this iterator current is null xor the iters current is null return false
	if ((bool)(m_current == nullptr) ^ (bool)(iter.m_current == nullptr))
		return false;
	//if both of the current are null
	if (m_current == nullptr && iter.m_current == nullptr)
		return true;
	//return if all components are equal
	return m_current->data == iter.m_current->data &&
		m_current->next == iter.m_current->next &&
		m_current->previous == iter.m_current->previous;
}

template<typename T>
inline const bool Iterator<T>::operator!=(const Iterator<T>& iter)
{
	if ((bool)(m_current == nullptr) ^ (bool)(iter.m_current == nullptr))
		return true;
	if (m_current == nullptr && iter.m_current == nullptr)
		return false;
	return !(m_current->data == iter.m_current->data &&
		m_current->next == iter.m_current->next &&
		m_current->previous == iter.m_current->previous);
}

template<typename T>
inline T Iterator<T>::operator*()
{
	return m_current->data;
}
