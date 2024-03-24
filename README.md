# StaxLinkedList

Doubly-linked list created for the Stax application. The API is designed using the conventions of the STL containers, and an STL-like iterator class is provided. This means that the LinkedList class can be used with the `range-based for loop` and other standard methods in the STL `<alogorithms>` header, such as `std::find`, `std::for_each`, etc. It is designed as a class template so it can be used with any type of data.

The `StaxApplicationData` struct is an example of an application data object that can be used with the LinkedList class. A specialization of the LinkedList\<TValue\> template for the StaxApplicationData struct is also provided in StaxAppData.h, named the `StaxAppData::LinkedList` type.

## API Documentation

API documentation created with Doxygen can be viewed here:

* [Main API Page](https://nam20485.github.io/StaxLinkedList/annotated.html)
* [LinkedList class](https://nam20485.github.io/StaxLinkedList/classLinkedList.html)
* [LinkedListIterator class](https://nam20485.github.io/StaxLinkedList/classLinkedListIterator.html)

## Tests

Automated tests are run on every commit as part of the CI/CD pipeline. Test results can be seen here:

## CI/CD Build Statuses

[![Deploy static content to Pages](https://github.com/nam20485/StaxLinkedList/actions/workflows/doxygen-gh-pages.yml/badge.svg)](https://github.com/nam20485/StaxLinkedList/actions/workflows/doxygen-gh-pages.yml)

[![MSBuild](https://github.com/nam20485/StaxLinkedList/actions/workflows/build-and-test.yml/badge.svg?branch=main)](https://github.com/nam20485/StaxLinkedList/actions/workflows/build-and-test.yml)

## Code

The majority of the LinkedList code can be found in LinkedList.h. The main.cpp file contains examples of usage of the LinkedList class. Test cases can be found in the Tests project's files.

* [LinkedList.h](StaxLinkedList/LinkedList.h)
* [main.cpp](StaxLinkedList/main.cpp)
* [StaxApplicationData.h](StaxLinkedList/StaxAppData.cpp)
* [LinkedListIterator.h](StaxLinkedList/LinkedListIterator.h)

## Build

To build and run the project, open the `\StaxLinkedList.sln` file in Visual Studio and build the project. Then you can run the project.
