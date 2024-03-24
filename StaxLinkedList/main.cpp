// StaxLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
#include "LinkedList.h"
#include "StaxAppData.h"


int main()
{
    // example with list of ints (see example with struct StaxApplicationData below...)
    LinkedList<int> ll;

    ll.push_front(-1);
    ll.push_back(0);
    ll.push_back(1);
    ll.push_back(2);
    ll.push_front(3);
    ll.push_front(4);
    ll.push_back(5);   

    // { 4 3 -1 0 1 2 5 }

    //ll.pop_front();
    //ll.pop_front();
    //ll.pop_front();
    //ll.pop_back();    
    
    // { 0 1 2 }

    std::cout << ll.toString() << std::endl;

    //
    // use the range-based for loop to iterate the values in the list
    //
    for (auto val : ll)
    {
        std::cout << val << ' ';
    }
    std::cout << std::endl;

    //
    // iterate the list values in reverse
    //
    for (auto it = ll.rbegin(); it != ll.rend(); --it)
    {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    //
    // using an example struct to represent Stax applicaiton data object
    //
    StaxAppData::LinkedList staxAppDataLinkedList;
    
    staxAppDataLinkedList.push_back(std::make_shared<StaxAppData>("https://api.stax.com/api:8080", "options.json", "<dbconnectionstring>", 1));
    staxAppDataLinkedList.push_back(std::make_shared<StaxAppData>("https://api.stax.com/api:8080", "options.json", "<dbconnectionstring>", 2));
    staxAppDataLinkedList.push_back(std::make_shared<StaxAppData>("https://api.stax.com/api:8080", "options.json", "<dbconnectionstring>", 3));
    staxAppDataLinkedList.push_front(std::make_shared<StaxAppData>("https://api.stax.com/api:8080", "options.json", "<dbconnectionstring>", 0));    

    for (auto appData : staxAppDataLinkedList)
    {
        appData->userId++;
        auto& apiUrl = appData->apiUrl;
        auto& optionsFile = appData->optionsFilename;     
    }   

    return 0;
}
