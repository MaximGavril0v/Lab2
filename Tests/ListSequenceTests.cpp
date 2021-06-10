#ifndef TEST_DB_LISTSEQUENCETESTS_H
#define TEST_DB_LISTSEQUENCETESTS_H

#include "gtest/gtest.h"
#include "../ListSequence.h"

TEST(ListSequence, InitDefault) {
    ListSequence<int> arr = ListSequence<int>();
    ASSERT_EQ(0, arr.GetLength());
    EXPECT_ANY_THROW(arr.GetFirst());
    EXPECT_ANY_THROW(arr.GetLast());
}

TEST(ListSequence, Append) {
    ListSequence<int> arr = ListSequence<int>();
    arr.Append(5);
    ASSERT_EQ (1, arr.GetLength());
    EXPECT_ANY_THROW(arr[-1]);
    EXPECT_ANY_THROW(arr[1]);
    EXPECT_EQ (5, arr[0]);

    arr[0] = 4;
    EXPECT_EQ (4, arr[0]);
    EXPECT_EQ (4, arr.GetFirst());
    EXPECT_EQ (4, arr.GetLast());
    EXPECT_ANY_THROW(arr[-1] = 1);
    EXPECT_ANY_THROW(arr[1] = 1);

    arr.Append(5);
    ASSERT_EQ (2, arr.GetLength());
    arr[0] = 1;
    EXPECT_EQ (1, arr[0]);
    EXPECT_EQ (5, arr[1]);
    EXPECT_EQ (1, arr.GetFirst());
    EXPECT_EQ (5, arr.GetLast());

    arr.Append(3);
    ASSERT_EQ (3, arr.GetLength());
    EXPECT_EQ (1, arr[0]);
    EXPECT_EQ (5, arr[1]);
    EXPECT_EQ (3, arr[2]);
    EXPECT_EQ (1, arr.GetFirst());
    EXPECT_EQ (3, arr.GetLast());
}

TEST(ListSequence, Prepend) {
    ListSequence<int> arr = ListSequence<int>();
    arr.Prepend(5);
    ASSERT_EQ (1, arr.GetLength());
    EXPECT_ANY_THROW(arr[-1]);
    EXPECT_ANY_THROW(arr[1]);
    EXPECT_EQ (5, arr[0]);

    arr[0] = 4;
    EXPECT_EQ (4, arr[0]);
    EXPECT_EQ (4, arr.GetFirst());
    EXPECT_EQ (4, arr.GetLast());
    EXPECT_ANY_THROW(arr[-1] = 1);
    EXPECT_ANY_THROW(arr[1] = 1);

    arr.Prepend(5);
    ASSERT_EQ (2, arr.GetLength());
    EXPECT_EQ (5, arr[0]);
    EXPECT_EQ (4, arr[1]);
    EXPECT_EQ (5, arr.GetFirst());
    EXPECT_EQ (4, arr.GetLast());

    arr.Prepend(3);
    ASSERT_EQ (3, arr.GetLength());
    EXPECT_EQ (3, arr[0]);
    EXPECT_EQ (5, arr[1]);
    EXPECT_EQ (4, arr[2]);
    EXPECT_EQ (3, arr.GetFirst());
    EXPECT_EQ (4, arr.GetLast());
}

TEST(ListSequence, InsertAt) {
    int a[] = {1, 2, 3};
    ListSequence<int> arr = ListSequence<int>(a, 3);
    arr.InsertAt(1, 4);
    ASSERT_EQ (4, arr.GetLength());
    EXPECT_EQ (1, arr[0]);
    EXPECT_EQ (4, arr[1]);
    EXPECT_EQ (2, arr[2]);
    EXPECT_EQ (3, arr[3]);
    EXPECT_EQ (1, arr.GetFirst());
    EXPECT_EQ (3, arr.GetLast());

    arr.InsertAt(0, 5);
    ASSERT_EQ (5, arr.GetLength());
    EXPECT_EQ (5, arr[0]);
    EXPECT_EQ (1, arr[1]);
    EXPECT_EQ (4, arr[2]);
    EXPECT_EQ (2, arr[3]);
    EXPECT_EQ (3, arr[4]);
    EXPECT_EQ (5, arr.GetFirst());
    EXPECT_EQ (3, arr.GetLast());

    arr.InsertAt(arr.GetLength() - 1, 6);
    ASSERT_EQ (6, arr.GetLength());
    EXPECT_EQ (5, arr[0]);
    EXPECT_EQ (1, arr[1]);
    EXPECT_EQ (4, arr[2]);
    EXPECT_EQ (2, arr[3]);
    EXPECT_EQ (6, arr[4]);
    EXPECT_EQ (3, arr[5]);
    EXPECT_EQ (5, arr.GetFirst());
    EXPECT_EQ (3, arr.GetLast());
}

TEST(ListSequence, PopFirst) {
    int a[] = {1, 2, 3};
    ListSequence<int> arr = ListSequence<int>(a, 3);
    arr.PopFirst();
    ASSERT_EQ (2, arr.GetLength());
    EXPECT_EQ (2, arr[0]);
    EXPECT_EQ (3, arr[1]);
    EXPECT_EQ (2, arr.GetFirst());
    EXPECT_EQ (3, arr.GetLast());

    arr.PopFirst();
    ASSERT_EQ (1, arr.GetLength());
    EXPECT_EQ (3, arr[0]);
    EXPECT_EQ (3, arr.GetFirst());
    EXPECT_EQ (3, arr.GetLast());

    arr.PopFirst();
    ASSERT_EQ (0, arr.GetLength());
    EXPECT_ANY_THROW (arr[0]);
    EXPECT_ANY_THROW(arr.GetFirst());
    EXPECT_ANY_THROW (arr.GetLast());
    EXPECT_ANY_THROW (arr.PopFirst(););
}

TEST(ListSequence, PopLast) {
    int a[] = {1, 2, 3};
    ListSequence<int> arr = ListSequence<int>(a, 3);
    arr.PopLast();
    ASSERT_EQ (2, arr.GetLength());
    EXPECT_EQ (1, arr[0]);
    EXPECT_EQ (2, arr[1]);
    EXPECT_EQ (1, arr.GetFirst());
    EXPECT_EQ (2, arr.GetLast());

    arr.PopLast();
    ASSERT_EQ (1, arr.GetLength());
    EXPECT_EQ (1, arr[0]);
    EXPECT_EQ (1, arr.GetFirst());
    EXPECT_EQ (1, arr.GetLast());

    arr.PopLast();
    ASSERT_EQ (0, arr.GetLength());
    EXPECT_ANY_THROW (arr[0]);
    EXPECT_ANY_THROW (arr.GetFirst());
    EXPECT_ANY_THROW (arr.GetLast());
    EXPECT_ANY_THROW(arr.PopLast());
}

TEST(ListSequence, InitFromArr) {
    int a[] = {1, 2, 3, 4, 5};
    EXPECT_ANY_THROW(ListSequence<int>(a, -1));
    EXPECT_ANY_THROW(ListSequence<int>(nullptr, 1));
    ListSequence<int> arr = ListSequence<int>(a, 5);
    ASSERT_EQ (5, arr.GetLength());

    arr.Append(6);
    ASSERT_EQ (6, arr.GetLength());
    EXPECT_EQ (1, arr[0]);
    EXPECT_EQ (2, arr[1]);
    EXPECT_EQ (3, arr[2]);
    EXPECT_EQ (4, arr[3]);
    EXPECT_EQ (5, arr[4]);
    EXPECT_EQ (6, arr[5]);

    arr.PopLast();
    EXPECT_ANY_THROW(arr[5]);
    ASSERT_EQ (5, arr.GetLength());
    arr[0] = 0;
    EXPECT_EQ (1, a[0]);
    EXPECT_EQ (0, arr[0]);
    EXPECT_EQ (2, arr[1]);
    EXPECT_EQ (3, arr[2]);
    EXPECT_EQ (4, arr[3]);
    EXPECT_EQ (5, arr[4]);
    arr = ListSequence<int>(a, 0);
    ASSERT_EQ (0, arr.GetLength());
}

TEST(ListSequence, InitFromListSequence) {
    int a[] = {1, 2, 3, 4, 5, 6};
    ListSequence<int> arr1 = ListSequence<int>(a, 5);
    ASSERT_EQ (5, arr1.GetLength());
    EXPECT_ANY_THROW(arr1[5]);
    ListSequence<int> arr2 = ListSequence<int>(arr1);
    ASSERT_EQ (5, arr2.GetLength());
    EXPECT_EQ (arr1[0], arr2[0]);
    EXPECT_EQ (arr1[1], arr2[1]);
    EXPECT_EQ (arr1[2], arr2[2]);
    EXPECT_EQ (arr1[3], arr2[3]);
    EXPECT_EQ (arr1[4], arr2[4]);

    arr1[0] = 2;
    EXPECT_EQ (arr1[0], 2);
    EXPECT_EQ (arr2[0], 1);
    arr2.Append(0);
    ASSERT_EQ (5, arr1.GetLength());
    ASSERT_EQ (6, arr2.GetLength());

    arr1 = ListSequence<int>();
    arr2 = ListSequence<int>(arr1);
    ASSERT_EQ (0, arr2.GetLength());
}

TEST(ListSequence, Concat) {
    int a[] = {1, 2, 3, 4, 5};
    ListSequence<int> arr1 = ListSequence<int>(a, 5);
    ListSequence<int> arr2 = ListSequence<int>(arr1);
    ListSequence<int> arr3 = *(arr1.Concat(arr2));
    ASSERT_EQ (arr1.GetLength() + arr2.GetLength(), arr3.GetLength());
    EXPECT_EQ (arr1[0], arr3[0]);
    EXPECT_EQ (arr1[1], arr3[1]);
    EXPECT_EQ (arr1[2], arr3[2]);
    EXPECT_EQ (arr1[3], arr3[3]);
    EXPECT_EQ (arr1[4], arr3[4]);
    EXPECT_EQ (arr2[0], arr3[0]);
    EXPECT_EQ (arr2[1], arr3[1]);
    EXPECT_EQ (arr2[2], arr3[2]);
    EXPECT_EQ (arr2[3], arr3[3]);
    EXPECT_EQ (arr2[4], arr3[4]);
}

TEST(ListSequence, Subsequence) {
    int a[] = {1, 2, 3, 4, 5};
    ListSequence<int> arr1 = ListSequence<int>(a, 5);
    ListSequence<int> arr2 = *(arr1.GetSubsequence(0, 0));
    ASSERT_EQ(arr2.GetLength(), 1);
    EXPECT_EQ (arr1[0], 1);
    EXPECT_ANY_THROW(arr2[1]);
    EXPECT_ANY_THROW(arr1.GetSubsequence(-1, 0));
    EXPECT_ANY_THROW(arr1.GetSubsequence(1, 0));
    EXPECT_ANY_THROW(arr1.GetSubsequence(1, 5));
    arr2 = *(arr1.GetSubsequence(0, 4));
    ASSERT_EQ(arr2.GetLength(), 5);
    EXPECT_EQ (arr1[0], arr2[0]);
    EXPECT_EQ (arr1[1], arr2[1]);
    EXPECT_EQ (arr1[2], arr2[2]);
    EXPECT_EQ (arr1[3], arr2[3]);
    EXPECT_EQ (arr1[4], arr2[4]);
    arr2 = *(arr1.GetSubsequence(2, 3));
    ASSERT_EQ(arr2.GetLength(), 2);
    EXPECT_EQ (arr1[2], arr2[0]);
    EXPECT_EQ (arr1[3], arr2[1]);
}

#endif

