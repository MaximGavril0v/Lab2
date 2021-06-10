#ifndef TEST_DB_STACKTESTS_H
#define TEST_DB_STACKTESTS_H

#include "gtest/gtest.h"
#include "../Stack.h"

TEST(Stack, Init) {
    Stack<int> stack = Stack<int>();
    EXPECT_ANY_THROW(stack.Pop());
    EXPECT_ANY_THROW(stack.Top());
    ASSERT_EQ(1, stack.isEmpty());
    stack.Push(5);
    ASSERT_EQ(5, stack.Top());
    ASSERT_EQ(0, stack.isEmpty());
    stack.Pop();
    ASSERT_EQ(1, stack.isEmpty());
}


#endif
