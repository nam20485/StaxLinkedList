#pragma once

#include <string>
#include <sstream>


template<typename TValue>
class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	struct Node;

	// O(1)
	int getCount() const;
	//Node* getHead() const	{ return head; }
	//Node* getTail() const	{ return tail; }	

	// O(1)
	void addFirst(TValue val);
	// O(1)
	void addLast(TValue val);

	// O(1)
	TValue peekFirst();
	// O(1)
	TValue peekLast();

	// O(1)
	TValue removeFirst();
	// O(1)
	TValue removeLast();

	std::string toString();

private:
	Node* head;
	Node* tail;
	int count;

	void addAfter(Node* node, TValue val);
	void addBefore(Node* node, TValue val);
	TValue removeNode(Node* node);
	void free();

};

template<typename TValue>
struct LinkedList<TValue>::Node
{
	Node(TValue val)
		: next(nullptr)
		, prev(nullptr)
		, data(val)
	{}

	TValue data;
	Node* next;
	Node* prev;

	std::string toString();
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
	free();
}

template<typename TValue>
inline int LinkedList<TValue>::getCount() const
{
	return count;
}

template<typename TValue>
inline void LinkedList<TValue>::addFirst(TValue val)
{
	addBefore(head, val);
}

template<typename TValue>
inline void LinkedList<TValue>::addLast(TValue val)
{		
	addAfter(tail, val);
}

template<typename TValue>
inline TValue LinkedList<TValue>::removeFirst()
{
	return removeNode(head);
}

template<typename TValue>
inline TValue LinkedList<TValue>::removeLast()
{
	return removeNode(tail);
}

template<typename TValue>
inline TValue LinkedList<TValue>::peekFirst()
{
	if (head == nullptr) throw std::runtime_error("list is empty");
	return head->data;
}

template<typename TValue>
inline TValue LinkedList<TValue>::peekLast()
{
	if (tail == nullptr) throw std::runtime_error("list is empty");
	return tail->data;
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

	delete node;
	count--;

	return val;
}

template<typename TValue>
inline void LinkedList<TValue>::free()
{
	while (tail != nullptr)
	{
		removeNode(tail);
	}	
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
inline std::string LinkedList<TValue>::Node::toString()
{
	std::stringstream ss;
	ss << '[' << data << ']';
	return ss.str();
}
