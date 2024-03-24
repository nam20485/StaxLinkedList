[![Build and Test](https://github.com/nam20485/StaxLinkedList/actions/workflows/build-and-test.yml/badge.svg)](https://github.com/nam20485/StaxLinkedList/actions/workflows/build-and-test.yml)
[![Deploy API Documentation](https://github.com/nam20485/StaxLinkedList/actions/workflows/doxygen-gh-pages.yml/badge.svg)](https://github.com/nam20485/StaxLinkedList/actions/workflows/doxygen-gh-pages.yml)

# StaxLinkedList

Doubly-linked list created for the Stax application. The API is designed using the conventions of the STL containers, and an STL-like iterator class is provided. This means that the LinkedList class can be used with the `range-based for loop` and other standard methods in the STL `<algorithm>` header, such as `std::find`, `std::for_each`, etc. It is designed as a class template so it can be used with any type of data.

>The `StaxApplicationData` struct is an example of an application data object that can be used with the LinkedList class. A specialization of the LinkedList\<TValue\> template for the StaxApplicationData struct is also provided in StaxAppData.h, named the `StaxAppData::LinkedList` type.

## Code

The majority of the LinkedList code can be found in `LinkedList.h`. The `main.cpp` file contains examples of usage of the LinkedList class. Test cases can be found in the `Tests` project's files.

* [LinkedList.h](StaxLinkedList/LinkedList.h)
* [main.cpp](StaxLinkedList/main.cpp)
* [LinkedListIterator.h](StaxLinkedList/LinkedListIterator.h)
* [StaxApplicationData.h](StaxLinkedList/StaxAppData.cpp)

## API Documentation

API documentation created with Doxygen can be viewed here:

* [Main API Page](https://nam20485.github.io/StaxLinkedList/annotated.html)
* [LinkedList class](https://nam20485.github.io/StaxLinkedList/classLinkedList.html)
* [LinkedListIterator class](https://nam20485.github.io/StaxLinkedList/classLinkedListIterator.html)

## Tests

Test cases can be found in the `Tests` project. The tests are written using the Google Test (GTest) testing framework. Automated tests run on every commit as part of the CI/CD pipeline.

>The random operations test are designed to stress test the LinkedList class, running 4,000,000 random operations on a linked list instance and then comparing the results to a `std::vector` that has had the same operations performed on it. The test checks that the linked list and vector have the same size and that the elements in the linked list are in the same order as the vector.

Test Case Files:

* [Logic Tests](Tests/LinkedListLogicTests.cpp)
* [Method Tests](Tests/LinkedListMethodTests.cpp)
* [Random Operations Test](Tests/RandomOperationsTests.cpp)

[Test results can be seen here.](https://github.com/nam20485/StaxLinkedList/actions/runs/8412559181/job/23033557118)

## Build

To build and run the project, open the `\StaxLinkedList.sln` file in Visual Studio and build the project. You can then run the project.
