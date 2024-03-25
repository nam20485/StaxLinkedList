#pragma once

#include <string>
#include <sstream>
#include "LinkedListIterator.h"

/**

    @class   LinkedList
    @brief   Doubley-linked list   

	@details ~ Follows STL container and iterator conventions. Compatible with range-based for loop and other methods in the <algorithm> header.
    @tparam  TValue - type of list's values

**/
template<typename TValue>
class LinkedList
{
public:
	/**
		@brief Construct an empty list
	**/
	LinkedList();
	~LinkedList();	

	using iterator = LinkedListIterator<TValue>;
	friend class iterator;
	//using const_iterator = ConstLinkedListIterator<TValue>;

	/**
		@brief  Returns size of the list

		Performs in O(1) constant time
		@retval size_t count of values in the list
	**/
	std::size_t size() const;

	/**
		@brief  Determines if the list is empty, i.e. it contains no values

		Performs in O(1) constant time
		@retval bool true if the list is empty, false if the list contains nodes
	**/
	bool empty() const;

	/**
		@brief Add an element to the front of the list

		Performs in O(1) constant time
		@param val - value to add
	**/
	void push_front(const TValue& val);	
	void push_front(TValue&& val);

	/**
		 @brief Add an element to the end of the list

		 Performs in O(1) constant time
		 @param val - value to add
	 **/
	void push_back(const TValue& val);
	void push_back(TValue&& val);

	/**
		@brief  Return the value at the beginning of the list, without removing it from the list

		Performs in O(1) constant time

		@exception std::runtime_error if list is empty
		@retval TValue value at the beginning of the list
	**/
	TValue front();
	const TValue front() const;

	/**
		@brief  Return the value at the end of the list, without removing it from the list

		Performs in O(1) constant time
		@exception std::runtime_error if list is empty
		@retval TValue value at the end of the list
	**/
	TValue back();
	const TValue back() const;

	/**
		@brief Removes the value at the beginning of the list and returns it

		Performs in O(1) constant time
		@exception std::runtime_error if list is empty
		@retval TValue value at the beginning of the list
	**/
	TValue pop_front();	

	/**
		@brief Removes the value at the end of the list and returns it

		Performs in O(1) constant time
		@exception std::runtime_error if list is empty
		@retval TValue value at the end of the list
	**/
	TValue pop_back();	
	
	/**
		@brief Removes all elements of the list

		Performs in O(n) linear time, where n = the number of values in the list
	**/
	void clear();

	iterator begin();
	iterator end();

	iterator rbegin();
	iterator rend();

	//const_iterator cbegin() const;
	//const_iterator cend() const;

	/**
		@brief Get string representation of list suitable for display

		Lists all values and marks the head and tail
		@retval  - std::string representation of list
	**/
	std::string toString() const;

private:
	// forward declaration (implementation below)
	struct Node;

	Node* head;
	Node* tail;

	int count;

	// Add the specified value AFTER the given node
	void addAfter(Node* node, const TValue& val);
	// Add the specified value BEFORE the given node
	void addBefore(Node* node, const TValue& val);

	// Remove the given node (and free it's memory)
	TValue removeNode(Node* node);	

};

/**
    @struct Node
    @brief  Represents a node in the LinkedList 
    @tparam TValue - type of Node's values
**/
template<typename TValue>
struct LinkedList<TValue>::Node
{
	Node(const TValue& val)
		: next(nullptr)
		, prev(nullptr)
		, data(val)
	{}

	~Node()
	{
		delete next;
		next = nullptr;
	}

	std::string toString() const;

private:
	TValue data;
	Node* next;
	Node* prev;

	friend class LinkedList<TValue>;
	friend class LinkedList<TValue>::iterator;
};

template<typename TValue>
inline LinkedList<TValue>::LinkedList()
	: head(nullptr)
	, tail(nullptr)
	, count(0)
{}

template<typename TValue>
inline LinkedList<TValue>::~LinkedList()
{
	clear();
}

template<typename TValue>
inline std::size_t LinkedList<TValue>::size() const
{
	return count;
}

template<typename TValue>
inline bool LinkedList<TValue>::empty() const
{
	return head == nullptr;
}

template<typename TValue>
inline void LinkedList<TValue>::push_front(const TValue& val)
{
	addBefore(head, val);
}

template<typename TValue>
inline void LinkedList<TValue>::push_front(TValue&& val)
{
	addBefore(head, std::move(val));
}

template<typename TValue>
inline void LinkedList<TValue>::push_back(const TValue& val)
{		
	addAfter(tail, val);
}

template<typename TValue>
inline void LinkedList<TValue>::push_back(TValue&& val)
{
	addAfter(tail, std::move(val));
	//push_back(val);
}

template<typename TValue>
inline TValue LinkedList<TValue>::pop_front()
{
	return removeNode(head);
}

template<typename TValue>
inline TValue LinkedList<TValue>::pop_back()
{
	return removeNode(tail);
}

template<typename TValue>
inline TValue LinkedList<TValue>::front()
{
	if (head == nullptr) throw std::runtime_error("list is empty");
	return head->data;
}

template<typename TValue>
inline const TValue LinkedList<TValue>::front() const
{
	if (head == nullptr) throw std::runtime_error("list is empty");
	return head->data;
}

template<typename TValue>
inline TValue LinkedList<TValue>::back()
{
	if (tail == nullptr) throw std::runtime_error("list is empty");
	return tail->data;
}

template<typename TValue>
inline const TValue LinkedList<TValue>::back() const
{
	if (tail == nullptr) throw std::runtime_error("list is empty");
	return tail->data;
}

template<typename TValue>
inline void LinkedList<TValue>::addAfter(Node* node, const TValue& val)
{
	auto newNode = new Node(val);	
	if (node != nullptr)
	{		
		newNode->prev = node;
		newNode->next = node->next;				
		node->next = newNode;
		if (newNode->next != nullptr)
		{
			// node was not the tail					
			newNode->next->prev = newNode;
		}
		else
		{
			// new tail (i.e. node was the tail)
			tail = newNode;
		}
	}	
	else
	{
		// adding into empty list
		head = newNode;
		tail = newNode;
	}	
	count++;
}

template<typename TValue>
inline void LinkedList<TValue>::addBefore(Node* node, const TValue& val)
{
	auto newNode = new Node(val);
	if (node != nullptr)
	{
		newNode->next = node;
		newNode->prev = node->prev;
		node->prev = newNode;
		if (newNode->prev != nullptr)
		{
			// node was not the head			
			newNode->prev->next = newNode;
		}
		else
		{
			// new head (node was the head)
			head = newNode;
		}
	}
	else
	{
		// empty list
		head = newNode;
		tail = newNode;
	}
	count++;
}

template<typename TValue>
inline TValue LinkedList<TValue>::removeNode(Node* node)
{
	if (head == nullptr) throw std::runtime_error("cannot remove from empty list");

	auto val = node->data;

	if (node->next != nullptr)
	{				
		node->next->prev = node->prev;		
	}
	else
	{
		// removing the tail
		tail = node->prev;
	}

	if (node->prev != nullptr)
	{
		node->prev->next = node->next;
	}
	else
	{
		// removing the head
		head = node->next;
	}

	//// set next = nullptr so we don't delete the rest of the list after the node we are removing
	node->next = nullptr;
	node->prev = nullptr;
	delete node;	

	count--;

	return val;
}

template<typename TValue>
inline void LinkedList<TValue>::clear()
{
	//while (!empty())
	//{
	//	removeNode(tail);
	//}
	delete head;
	head = nullptr;	
	tail = nullptr;
	count = 0;
}

template<typename TValue>
inline LinkedList<TValue>::iterator LinkedList<TValue>::begin()
{
	return iterator(head);
}

template<typename TValue>
inline LinkedList<TValue>::iterator LinkedList<TValue>::end()
{
	return iterator(nullptr);
}

template<typename TValue>
inline LinkedList<TValue>::iterator LinkedList<TValue>::rbegin()
{
	return iterator(tail);
}

template<typename TValue>
inline LinkedList<TValue>::iterator LinkedList<TValue>::rend()
{
	return iterator(nullptr);
}

//template<typename TValue>
//inline LinkedList<TValue>::const_iterator LinkedList<TValue>::cbegin() const
//{
//	return const_iterator(head);
//}
//
//template<typename TValue>
//inline LinkedList<TValue>::const_iterator LinkedList<TValue>::cend() const
//{
//	return const_iterator(nullptr);
//}

template<typename TValue>
inline std::string LinkedList<TValue>::toString() const
{
	std::stringstream ss;

	auto n = head;
	while (n != nullptr)
	{
		ss << n->toString();
		if (n->next != nullptr)
		{
			ss << "<->";
		}
		n = n->next;
	}

	ss << std::endl;

	int headthNode = 0;
	auto hn = head;
	while (hn != nullptr)
	{		
		if (hn == head)
		{
			break;
		}
		headthNode++;
		hn = hn->next;		
	}

	int tailthNode = 0;
	auto tn = head;
	while (tn != nullptr)
	{		
		if (tn == tail)
		{
			break;
		}
		tailthNode++;
		tn = tn->next;		
	}

	if (headthNode > 0)
	{
		ss << std::string(headthNode*6, ' ');
	}
	ss << " h";

	if (tailthNode > 0)
	{
		ss << std::string((tailthNode-headthNode) * 6, ' ');
	}
	ss << "t";

	return ss.str();
}

template<typename TValue>
inline std::string LinkedList<TValue>::Node::toString() const
{
	std::stringstream ss;
	ss << '[' << data << ']';
	return ss.str();
}
