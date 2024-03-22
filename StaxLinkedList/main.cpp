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

    ll.push_front(-1);
    ll.push_back(0);
    ll.push_back(1);
    ll.push_back(2);
    ll.push_front(3);
    ll.push_front(4);
    ll.push_back(5);

    //ll.pop_front();
    //ll.pop_front();
    //ll.pop_front();
    //ll.pop_back();

    // 4 3 -1 0 1 2 5
    // 012

    std::cout << ll.toString() << std::endl;

    for (auto val : ll)
    {
        std::cout << val;
    }

    //StaxAppData::LinkedList staxAppDataLinkedList;

    //staxAppDataLinkedList.push_front(std::make_shared<StaxAppData>("", "", "", -1));
    //std::cout << staxAppDataLinkedList.toString();

}
