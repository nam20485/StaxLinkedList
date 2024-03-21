#include "pch.h"
#include "LinkedList.h"
#include "StaxAppData.h"

enum class Operation
{
	AddFirst,
	AddLast,
	PeekFirst,
	PeekLast,
	RemoveFirst,
	RemoveLast,
};

const int OPERATION_COUNT = 6;

TEST(RandomTests, RandomOperationsProduceCorrectList) {
	
	LinkedList<int> linkedList;
	std::vector<int> list;

	auto iterations = static_cast<int>(4e6);	// 4,000,000
	auto maxInt = 1000;

	std::srand(static_cast<unsigned>(std::time(0)));

	for (int i = 0; i < iterations; i++)
	{
		auto val = std::rand()%maxInt;
		auto operation = static_cast<Operation>(std::rand() % OPERATION_COUNT);

		switch (operation)
		{
		case Operation::AddFirst:
			linkedList.addFirst(val);
			list.insert(list.begin(), val);
			break;
		case Operation::AddLast:
			linkedList.addLast(val);
			list.push_back(val);
			break;
		case Operation::RemoveFirst:
			if (linkedList.getCount() > 0)
			{
				linkedList.removeFirst();
				list.erase(list.begin());
			}
			break;
		case Operation::RemoveLast:
			if (linkedList.getCount() > 0)
			{
				linkedList.removeLast();
				list.pop_back();
			}
			break;
		case Operation::PeekFirst:
			if (linkedList.getCount() > 0)
			{
				auto val = linkedList.peekFirst();
				ASSERT_EQ(val, list.front());
			}
			break;
		case Operation::PeekLast:
			if (linkedList.getCount() > 0)
			{
				auto val = linkedList.peekLast();
				ASSERT_EQ(val, list.back());
			}
			break;
		}		
	}

	// check if lists are the same
	for (auto val : list)
	{
		auto llVal = linkedList.removeFirst();
		ASSERT_EQ(llVal, val);		
	}

	// check if linked list is empty, i.e. it was the same size as the verification list
	ASSERT_EQ(linkedList.getCount(), 0);
}

TEST(LinkedListTests, TestAddFirstOnEmptyList)
{
	StaxAppData::LinkedList ll;
	
	ASSERT_EQ(ll.getCount(), 0);
	
	auto data = std::make_shared<StaxAppData>("a", "b", "c", 99);
	ll.addFirst(data);

	ASSERT_EQ(ll.getCount(), 1);

	ASSERT_EQ(ll.peekFirst()->userId, data->userId);
}

TEST(LinkedListTests, TestAddLastOnEmptyList)
{
	StaxAppData::LinkedList ll;

	ASSERT_EQ(ll.getCount(), 0);

	auto data = std::make_shared<StaxAppData>("a", "b", "c", 99);
	ll.addLast(data);

	ASSERT_EQ(ll.getCount(), 1);

	ASSERT_EQ(ll.peekFirst()->userId, data->userId);
}