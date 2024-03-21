#include "pch.h"
#include "LinkedList.h"
#include "StaxAppData.h"

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

TEST(LinkedListTests, TestAddFirstOnNonEmptyList)
{
	StaxAppData::LinkedList ll;

	ASSERT_EQ(ll.getCount(), 0);

	auto data1 = std::make_shared<StaxAppData>("a", "b", "c", 1);
	ll.addFirst(data1);
	auto data2 = std::make_shared<StaxAppData>("a", "b", "c", 2);
	ll.addFirst(data2);

	ASSERT_EQ(ll.getCount(), 2);
	ASSERT_EQ(ll.peekFirst()->userId, data2->userId);
}

TEST(LinkedListTests, TestAddLastOnNonEmptyList)
{
	StaxAppData::LinkedList ll;

	ASSERT_EQ(ll.getCount(), 0);

	auto data1 = std::make_shared<StaxAppData>("a", "b", "c", 1);
	ll.addFirst(data1);
	auto data2 = std::make_shared<StaxAppData>("a", "b", "c", 2);
	ll.addLast(data2);

	ASSERT_EQ(ll.getCount(), 2);
	ASSERT_EQ(ll.peekLast()->userId, data2->userId);
}

TEST(LinkedListTests, TestPeekFirst)
{
	StaxAppData::LinkedList ll;

	ASSERT_EQ(ll.getCount(), 0);

	auto data1 = std::make_shared<StaxAppData>("a", "b", "c", 1);
	ll.addFirst(data1);
	ASSERT_EQ(ll.peekFirst()->userId, data1->userId);

	auto data2 = std::make_shared<StaxAppData>("a", "b", "c", 2);
	ll.addFirst(data2);
	ASSERT_EQ(ll.peekFirst()->userId, data2->userId);

	auto data3 = std::make_shared<StaxAppData>("a", "b", "c", 3);
	ll.addLast(data3);
	ASSERT_EQ(ll.peekFirst()->userId, data2->userId);
}

TEST(LinkedListTests, TestPeekLast)
{
	StaxAppData::LinkedList ll;

	ASSERT_EQ(ll.getCount(), 0);

	auto data1 = std::make_shared<StaxAppData>("a", "b", "c", 1);
	ll.addFirst(data1);
	ASSERT_EQ(ll.peekLast()->userId, data1->userId);

	auto data2 = std::make_shared<StaxAppData>("a", "b", "c", 2);
	ll.addFirst(data2);
	ASSERT_EQ(ll.peekLast()->userId, data1->userId);

	auto data3 = std::make_shared<StaxAppData>("a", "b", "c", 3);
	ll.addLast(data3);
	ASSERT_EQ(ll.peekLast()->userId, data3->userId);
}

TEST(LinkedListTests, TestRemoveFirst)
{
	StaxAppData::LinkedList ll;

	ASSERT_EQ(ll.getCount(), 0);

	auto data1 = std::make_shared<StaxAppData>("a", "b", "c", 1);
	ll.addFirst(data1);
	ASSERT_EQ(ll.peekFirst()->userId, data1->userId);

	auto val1 = ll.removeFirst();
	ASSERT_EQ(val1->userId, data1->userId);
	ASSERT_EQ(ll.getCount(), 0);

	auto data2 = std::make_shared<StaxAppData>("a", "b", "c", 2);
	ll.addLast(data2);
	auto data3 = std::make_shared<StaxAppData>("a", "b", "c", 3);
	ll.addLast(data3);

	auto val = ll.removeFirst();
	ASSERT_EQ(val->userId, data2->userId);
	ASSERT_EQ(ll.getCount(), 1);

	val = ll.removeFirst();
	ASSERT_EQ(val->userId, data3->userId);
	ASSERT_EQ(ll.getCount(), 0);
}

TEST(LinkedListTests, TestRemoveLast)
{
	StaxAppData::LinkedList ll;

	ASSERT_EQ(ll.getCount(), 0);

	auto data1 = std::make_shared<StaxAppData>("a", "b", "c", 1);
	ll.addFirst(data1);
	ASSERT_EQ(ll.peekFirst()->userId, data1->userId);

	auto val1 = ll.removeLast();
	ASSERT_EQ(val1->userId, data1->userId);
	ASSERT_EQ(ll.getCount(), 0);

	auto data2 = std::make_shared<StaxAppData>("a", "b", "c", 2);
	ll.addLast(data2);
	auto data3 = std::make_shared<StaxAppData>("a", "b", "c", 3);
	ll.addLast(data3);

	auto val = ll.removeLast();
	ASSERT_EQ(val->userId, data3->userId);
	ASSERT_EQ(ll.getCount(), 1);

	val = ll.removeLast();
	ASSERT_EQ(val->userId, data2->userId);
	ASSERT_EQ(ll.getCount(), 0);
}
