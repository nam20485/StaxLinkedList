// StaxLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
#include "LinkedList.h"
#include "StaxAppData.h"



int main()
{
    //LinkedList<std::shared_ptr<StaxAppData>> ll;
    LinkedList<int> ll;

    ll.addFirst(-1);
    ll.addLast(0);
    ll.addLast(1);
    ll.addLast(2);
    ll.addFirst(3);
    ll.addFirst(4);
    ll.addLast(5);

    ll.removeFirst();
    ll.removeFirst();
    ll.removeFirst();
    ll.removeLast();

    // 4 3 -1 0 1 2 5
    // 012

    std::cout << ll.toString();

    StaxAppData::LinkedList staxAppDataLinkedList;

    staxAppDataLinkedList.addFirst(std::make_shared<StaxAppData>("", "", "", -1));
    std::cout << staxAppDataLinkedList.toString();

}
