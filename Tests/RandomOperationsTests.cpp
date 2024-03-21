#include "pch.h"
#include "LinkedList.h"


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
	auto maxInt = 100000;

	std::srand(static_cast<unsigned>(std::time(0)));

	for (int i = 0; i < iterations; i++)
	{
		auto val = std::rand() % maxInt;
		auto operation = static_cast<Operation>(std::rand() % OPERATION_COUNT);

		switch (operation)
		{
		case Operation::AddFirst:
			linkedList.push_front(val);
			list.insert(list.begin(), val);
			break;
		case Operation::AddLast:
			linkedList.push_back(val);
			list.push_back(val);
			break;
		case Operation::RemoveFirst:
			if (linkedList.size() > 0)
			{
				linkedList.pop_front();
				list.erase(list.begin());
			}
			break;
		case Operation::RemoveLast:
			if (linkedList.size() > 0)
			{
				linkedList.pop_back();
				list.pop_back();
			}
			break;
		case Operation::PeekFirst:
			if (linkedList.size() > 0)
			{
				auto val = linkedList.front();
				ASSERT_EQ(val, list.front());
			}
			break;
		case Operation::PeekLast:
			if (linkedList.size() > 0)
			{
				auto val = linkedList.back();
				ASSERT_EQ(val, list.back());
			}
			break;
		}
	}

	// check if lists are the same
	for (auto val : list)
	{
		auto llVal = linkedList.pop_front();
		ASSERT_EQ(llVal, val);
	}

	// check if linked list is empty, i.e. it was the same size as the verification list
	ASSERT_EQ(linkedList.size(), 0);
}
