#include "..\..\..\lab2\mp2-lab2-matrix\gtest\gtest.h"
#include "C:\Users\KDFX Team\Desktop\hjgjgh\mp2-lab4-queue\mp2-lab4-queue\queue.h"

TEST(TQueue, can_create_queue)
{
	ASSERT_NO_THROW(TQueue<int> c(3));
}

TEST(TQueue, cant_create_queue_with_negative_size)
{
	ASSERT_ANY_THROW(TQueue<int> c(-1));
}

TEST(TQueue, cant_push_element_in_full_queue)
{
	TQueue<int> c(3);
	for (int i = 0; i < 3; i++)
	{
		c.Push(i);
	}
	ASSERT_ANY_THROW(c.Push(1));
}
TEST(TQueue, can_push_element_in_queue)
{
	TQueue<int> c(3);
	ASSERT_NO_THROW(c.Push(1));
	
}
TEST(TQueue, cant_pop_element_in_empty_queue)
{
	TQueue<int> c(3);
	ASSERT_ANY_THROW(c.Pop());
}
TEST(TQueue, can_pop_element_in_queue)
{
	TQueue<int> c(3);
	for (int i = 0; i < 3; i++)
	{
		c.Push(i);
	}
	EXPECT_EQ(c.Pop(), 0);
}


