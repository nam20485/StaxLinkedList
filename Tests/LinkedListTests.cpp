#include "pch.h"
#include "LinkedList.h"
#include "StaxAppData.h"

TEST(LinkedListTests, TestAddFirstOnEmptyList)
{
	StaxAppData::LinkedList ll;
	
	ASSERT_EQ(ll.size(), 0);
	
	auto data = std::make_shared<StaxAppData>("a", "b", "c", 99);
	ll.push_front(data);

	ASSERT_EQ(ll.size(), 1);
	ASSERT_EQ(ll.front()->userId, data->userId);
}

TEST(LinkedListTests, TestAddLastOnEmptyList)
{
	StaxAppData::LinkedList ll;

	ASSERT_EQ(ll.size(), 0);

	auto data = std::make_shared<StaxAppData>("a", "b", "c", 99);
	ll.push_back(data);

	ASSERT_EQ(ll.size(), 1);
	ASSERT_EQ(ll.front()->userId, data->userId);
}

TEST(LinkedListTests, TestAddFirstOnNonEmptyList)
{
	StaxAppData::LinkedList ll;

	ASSERT_EQ(ll.size(), 0);

	auto data1 = std::make_shared<StaxAppData>("a", "b", "c", 1);
	ll.push_front(data1);
	auto data2 = std::make_shared<StaxAppData>("a", "b", "c", 2);
	ll.push_front(data2);

	ASSERT_EQ(ll.size(), 2);
	ASSERT_EQ(ll.front()->userId, data2->userId);
}

TEST(LinkedListTests, TestAddLastOnNonEmptyList)
{
	StaxAppData::LinkedList ll;

	ASSERT_EQ(ll.size(), 0);

	auto data1 = std::make_shared<StaxAppData>("a", "b", "c", 1);
	ll.push_front(data1);
	auto data2 = std::make_shared<StaxAppData>("a", "b", "c", 2);
	ll.push_back(data2);

	ASSERT_EQ(ll.size(), 2);
	ASSERT_EQ(ll.back()->userId, data2->userId);
}

TEST(LinkedListTests, TestPeekFirst)
{
	StaxAppData::LinkedList ll;

	ASSERT_EQ(ll.size(), 0);

	auto data1 = std::make_shared<StaxAppData>("a", "b", "c", 1);
	ll.push_front(data1);
	ASSERT_EQ(ll.front()->userId, data1->userId);

	auto data2 = std::make_shared<StaxAppData>("a", "b", "c", 2);
	ll.push_front(data2);
	ASSERT_EQ(ll.front()->userId, data2->userId);

	auto data3 = std::make_shared<StaxAppData>("a", "b", "c", 3);
	ll.push_back(data3);
	ASSERT_EQ(ll.front()->userId, data2->userId);
}

TEST(LinkedListTests, TestPeekLast)
{
	StaxAppData::LinkedList ll;

	ASSERT_EQ(ll.size(), 0);

	auto data1 = std::make_shared<StaxAppData>("a", "b", "c", 1);
	ll.push_front(data1);
	ASSERT_EQ(ll.back()->userId, data1->userId);

	auto data2 = std::make_shared<StaxAppData>("a", "b", "c", 2);
	ll.push_front(data2);
	ASSERT_EQ(ll.back()->userId, data1->userId);

	auto data3 = std::make_shared<StaxAppData>("a", "b", "c", 3);
	ll.push_back(data3);
	ASSERT_EQ(ll.back()->userId, data3->userId);
}

TEST(LinkedListTests, TestRemoveFirst)
{
	StaxAppData::LinkedList ll;

	ASSERT_EQ(ll.size(), 0);

	auto data1 = std::make_shared<StaxAppData>("a", "b", "c", 1);
	ll.push_front(data1);
	ASSERT_EQ(ll.front()->userId, data1->userId);

	auto val1 = ll.pop_front();
	ASSERT_EQ(val1->userId, data1->userId);
	ASSERT_EQ(ll.size(), 0);

	auto data2 = std::make_shared<StaxAppData>("a", "b", "c", 2);
	ll.push_back(data2);
	auto data3 = std::make_shared<StaxAppData>("a", "b", "c", 3);
	ll.push_back(data3);

	auto val = ll.pop_front();
	ASSERT_EQ(val->userId, data2->userId);
	ASSERT_EQ(ll.size(), 1);

	val = ll.pop_front();
	ASSERT_EQ(val->userId, data3->userId);
	ASSERT_EQ(ll.size(), 0);
}

TEST(LinkedListTests, TestRemoveLast)
{
	StaxAppData::LinkedList ll;

	ASSERT_EQ(ll.size(), 0);

	auto data1 = std::make_shared<StaxAppData>("a", "b", "c", 1);
	ll.push_front(data1);
	ASSERT_EQ(ll.front()->userId, data1->userId);

	auto val1 = ll.pop_back();
	ASSERT_EQ(val1->userId, data1->userId);
	ASSERT_EQ(ll.size(), 0);

	auto data2 = std::make_shared<StaxAppData>("a", "b", "c", 2);
	ll.push_back(data2);
	auto data3 = std::make_shared<StaxAppData>("a", "b", "c", 3);
	ll.push_back(data3);

	auto val = ll.pop_back();
	ASSERT_EQ(val->userId, data3->userId);
	ASSERT_EQ(ll.size(), 1);

	val = ll.pop_back();
	ASSERT_EQ(val->userId, data2->userId);
	ASSERT_EQ(ll.size(), 0);
}
