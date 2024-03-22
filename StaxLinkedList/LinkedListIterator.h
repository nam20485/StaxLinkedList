#pragma once

#include <iterator>

template<typename TValue> class LinkedList;

template<typename TValue>
class LinkedListIterator// : public std::iterator<std::, TValue>
{
public:

	using iterator_category = std::bidirectional_iterator_tag;
	using value_type = typename std::remove_cv<TValue>::type;
	using difference_type = std::ptrdiff_t;
	using pointer = TValue*;
	using reference = TValue&;

	LinkedListIterator(LinkedList<TValue>::Node* current)
		:current(current)
	{}

	reference operator*();
	//pointer operator->();
	const LinkedListIterator<TValue>& operator++();
	const LinkedListIterator<TValue>& operator--();
	bool operator==(const LinkedListIterator<TValue>& other);
	bool operator!=(const LinkedListIterator<TValue>& other);

protected:
	LinkedList<TValue>::Node* current;

};

template<typename TValue>
inline LinkedListIterator<TValue>::reference LinkedListIterator<TValue>::operator*()
{
	return this->current->data;
}

//template<typename TValue>
//inline LinkedListIterator<TValue>::pointer LinkedListIterator<TValue>::operator->()
//{
//	return this->current;
//}

template<typename TValue>
inline const LinkedListIterator<TValue>& LinkedListIterator<TValue>::operator++()
{
	current = current->next;
	return *this;
}

template<typename TValue>
inline const LinkedListIterator<TValue>& LinkedListIterator<TValue>::operator--()
{
	current = current->prev;
	return *this;
}

template<typename TValue>
inline bool LinkedListIterator<TValue>::operator==(const LinkedListIterator<TValue>& other)
{
	//return other.current != nullptr && this->current == other.current;
	return this->current == other.current;
}

template<typename TValue>
inline bool LinkedListIterator<TValue>::operator!=(const LinkedListIterator<TValue>& other)
{
	return this->current != other.current;
}

//template<typename TValue>
//class ConstLinkedListIterator : public LinkedListIterator<TValue>
//{
//public:
//	ConstLinkedListIterator(TValue* current)
//		: LinkedListIterator<TValue>(current)
//	{}
//	
//	const LinkedListIterator<TValue>::reference operator*() const;
//};
//
//template<typename TValue>
//inline const LinkedListIterator<TValue>::reference ConstLinkedListIterator<TValue>::operator*() const
//{
//	return this->current->data;
//}
