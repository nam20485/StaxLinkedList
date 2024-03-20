#pragma once

#include <string>
#include <sstream>


template<typename TValue>
class LinkedList
{
public:
	LinkedList()
		: head(nullptr)
		, tail(nullptr)
	{}

	struct Node;

	// O(1)
	void addFirst(TValue val);
	// O(1)
	void addLast(TValue val);

	TValue removeFirst();
	TValue removeLast();

	std::string toString();

private:
	Node* head;
	Node* tail;
	int count;

	void addAfter(Node* node, TValue val);
	void addBefore(Node* node, TValue val);
	void removeNode(Node* node);

};

template<typename TValue>
inline void LinkedList<TValue>::addFirst(TValue val)
{
	addBefore(head, val);

	//auto newNode = new Node(val);
	//if (head != nullptr)
	//{
	//	newNode->next = head;
	//	head->prev = newNode;		
	//}
	//else
	//{
	//	// empty list
	//	tail = head;
	//}
	//head = newNode;
	//count++;
}

template<typename TValue>
inline void LinkedList<TValue>::addLast(TValue val)
{	
	//auto newNode = new Node(val);
	//if (tail != nullptr)
	//{
	//	newNode->prev = tail;
	//	tail->next = newNode;
	//}
	//else
	//{
	//	// empty list
	//	head = newNode;
	//}
	//tail = newNode;
	//count++;
	addAfter(tail, val);
}

template<typename TValue>
inline TValue LinkedList<TValue>::removeFirst()
{
	if (head == nullptr)
	{

	}
}

template<typename TValue>
inline TValue LinkedList<TValue>::removeLast()
{
	return TValue();
}

template<typename TValue>
inline std::string LinkedList<TValue>::toString()
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


	return ss.str();
}

template<typename TValue>
inline void LinkedList<TValue>::addAfter(Node* node, TValue val)
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
inline void LinkedList<TValue>::addBefore(Node* node, TValue val)
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
inline void LinkedList<TValue>::removeNode(Node* node)
{
	return nullptr;
}

template<typename TValue>
struct LinkedList<TValue>::Node
{
	Node(TValue val);

	TValue data;
	Node* next;
	Node* prev;

	std::string toString();
};

template<typename TValue>
inline LinkedList<TValue>::Node::Node(TValue val)
	: next(nullptr)
	, prev(nullptr)
{
	data = val;
}

template<typename TValue>
inline std::string LinkedList<TValue>::Node::toString()
{
	std::stringstream ss;
	ss << '[' << data << ']';
	return ss.str();
}
;
