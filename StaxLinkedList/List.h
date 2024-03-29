#pragma once

#include "IStlContainer.h"
#include "LinkedList.h"


/**

    @class   List
    @brief   A vector style dynamic array/list built on top of a LinkedList to provide the O(1)-constant time
			 complexity operations of a LinkedList for the majority of operations a vector needs. The only linear time operation 
			 is now random access and insert. For instance, Insert at front and back are still O(1), and resize() operation
			 is no longer needed.
    @details ~
    @tparam  TValue - 

**/
template<typename TValue>
class List : public LinkedList<TValue>
{
public:
	
	std::string toString() const override;

	LinkedList<TValue>::reference operator[](LinkedList<TValue>::size_type pos);
	LinkedList<TValue>::const_reference operator[](LinkedList<TValue>::size_type pos) const;

	LinkedList<TValue>::reference at(LinkedList<TValue>::size_type pos);
	LinkedList<TValue>::const_reference at(LinkedList<TValue>::size_type pos) const;

	

private:
	

};

template<typename TValue>
inline std::string List<TValue>::toString() const
{
	return std::string();
}

template<typename TValue>
inline LinkedList<TValue>::reference List<TValue>::operator[](LinkedList<TValue>::size_type pos)
{
	return at(pos);
}

template<typename TValue>
inline LinkedList<TValue>::const_reference List<TValue>::operator[](LinkedList<TValue>::size_type pos) const
{
	return at(pos);
}
