#pragma once

#include <iterator>

template<typename TValue> class LinkedList;

template<typename TValue>
class LinkedListIterator : public std::iterator<std::forward_iterator_tag, TValue>
{
public:
	LinkedListIterator(LinkedList<TValue>::Node* current)
		:current(current)
	{}

	TValue& operator*();
	const LinkedListIterator<TValue>& operator++();
	bool operator!=(const LinkedListIterator<TValue>& other);

private:
	LinkedList<TValue>::Node* current;

};

template<typename TValue>
inline TValue& LinkedListIterator<TValue>::operator*()
{
	return current->data;
}

template<typename TValue>
inline const LinkedListIterator<TValue>& LinkedListIterator<TValue>::operator++()
{
	current = current->next;
	return *this;
}

template<typename TValue>
inline bool LinkedListIterator<TValue>::operator!=(const LinkedListIterator<TValue>& other)
{
	return this->current != other.current;
}
