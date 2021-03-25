#include "TQueueList.h"
#include <gtest.h>

TEST(Queue, can_create_queue)
{
    ASSERT_NO_THROW(TQueueList<int>());
}


TEST(Queue, can_push_item_to_queue)
{
    TQueueList<int> s;
    ASSERT_NO_THROW(s.push(1));
}

TEST(Stack, can_copy_stack)
{
    TQueueList<int> s;
    for (int i = 0; i < 20; ++i) {
        s.push(i);
    }
    TQueueList<int> b = s;

    for (int j = 0; j < 20; ++j) {
        EXPECT_EQ(b.pop(), j);
    }
    ASSERT_NO_THROW(s.push(1));
}

TEST(Queue, can_pop_item_from_queue)
{
    TQueueList<int> s;
    s.push(1);
    int number = s.pop();
    EXPECT_EQ(number, 1);
}

TEST(Queue, default_queue_is_empty)
{
    TQueueList<int> s;
    EXPECT_EQ(s.is_empty(), true);
}

TEST(Queue, item_pop_makes_queue_empty)
{
    TQueueList<int> s;
    s.push(1);
    int number = s.pop();
    EXPECT_EQ(s.is_empty(), true);
}

TEST(Queue, queue_with_items_is_not_empty)
{
    TQueueList<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    EXPECT_EQ(s.is_empty(), false);
}

TEST(Queue, cant_pop_item_from_empty_queue)
{
    TQueueList<int> s;
    s.push(1);
    s.pop();
    ASSERT_ANY_THROW(s.pop());
}

TEST(Queue, can_get_max_element)
{
    TQueueList<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    EXPECT_EQ(s.get_max(), 3);
}

TEST(Queue, can_get_least_element)
{
    TQueueList<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    EXPECT_EQ(s.get_least(), 1);
}

