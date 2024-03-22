#pragma once

#include <string>
#include <sstream>
#include "LinkedListIterator.h"


template<typename TValue>
class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	struct Node;

	using Iterator = LinkedListIterator;

	// O(1)
	std::size_t size() const;
	bool empty() const;

	// O(1)
	void push_front(const TValue& val);	
	void push_back(const TValue& val);

	// O(1)
	TValue front() const;	
	TValue back() const;

	// O(1)
	TValue pop_front();	
	TValue pop_back();

	std::string toString() const;

	//
	// STL convention-compatible methods	
	//
	// These methods make this collection compatible with the STL functionality, such as std::equal(), <algorithms>, std::back_inserter, etc. 
	void clear();

	//Node* getHead() const	{ return head; }
	//Node* getTail() const	{ return tail; }	

private:
	Node* head;
	Node* tail;
	int count;

	void addAfter(Node* node, const TValue& val);
	void addBefore(Node* node, const TValue& val);
	TValue removeNode(Node* node);	

};

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

	TValue data;
	Node* next;
	Node* prev;

	std::string toString() const;
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
inline void LinkedList<TValue>::push_back(const TValue& val)
{		
	addAfter(tail, val);
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
inline TValue LinkedList<TValue>::front() const
{
	if (head == nullptr) throw std::runtime_error("list is empty");
	return head->data;
}

template<typename TValue>
inline TValue LinkedList<TValue>::back() const
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
