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
	std::size_t size() const;
	bool empty() const;

	// O(1)
	void push_front(TValue val);	
	void push_back(TValue val);

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

	void addAfter(Node* node, TValue val);
	void addBefore(Node* node, TValue val);
	TValue removeNode(Node* node);

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
	return count == 0;
}

template<typename TValue>
inline void LinkedList<TValue>::push_front(TValue val)
{
	addBefore(head, val);
}

template<typename TValue>
inline void LinkedList<TValue>::push_back(TValue val)
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
inline void LinkedList<TValue>::clear()
{
	while (tail != nullptr)
	{
		removeNode(tail);
	}	
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
