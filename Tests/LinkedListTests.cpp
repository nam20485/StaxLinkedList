#include "pch.h"
#include "LinkedList.h"

enum class Operation
{
	AddFirst,
	AddLast,
	RemoveFirst,
	RemoveLast
};

TEST(TestCaseName, TestName) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);

	LinkedList<int> linkedList;
	std::vector<int> list;

	int iterations = 100;
	int maxInt = 1000;

	std::srand(std::time(0));

	for (int i = 0; i < iterations; i++)
	{
		int val = std::rand()%maxInt;
		switch (std::rand() % 4)
		{
		case (int) Operation::AddFirst:
			linkedList.addFirst(val);
			list.insert(list.begin(), val);
			break;
		case (int) Operation::AddLast:
			linkedList.addLast(val);
			list.push_back(val);
			break;
		case (int) Operation::RemoveFirst:
			linkedList.removeFirst();
			list.erase(list.begin());
			break;
		case (int) Operation::RemoveLast:
			linkedList.removeLast();
			list.pop_back();
			break;
		}

		// check if lists are the same
		for (auto val : list)
		{
			auto llVal = linkedList.removeFirst();
			ASSERT_EQ(llVal, val);
		}
	}	
}