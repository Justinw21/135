#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "funcs.h"

TEST_CASE("empty") {
  std::vector<int> list;
  heapsort(list);
  CHECK(list.empty());
}

TEST_CASE("Heap")
{
    std::vector<int> list1 = {2, 3, 6, 4, 5};
    heapsort(list1);
    CHECK(list1[0] == 2);
    CHECK(list1[1] == 3);
    CHECK(list1[2] == 4);
    CHECK(list1[3] == 5);
    CHECK(list1[4] == 6);
}

TEST_CASE("Ascending")
{
    std::vector<int> list2 = {1, 2, 3, 4, 5};
    heapsort(list2);
    CHECK(list2[0] == 1);
    CHECK(list2[1] == 2);
    CHECK(list2[2] == 3);
    CHECK(list2[3] == 4);
    CHECK(list2[4] == 5);
}

TEST_CASE("Descending")
{
    std::vector<int> list3 = {5, 4, 3, 2, 1};
    heapsort(list3);
    CHECK(list3[0] == 1);
    CHECK(list3[1] == 2);
    CHECK(list3[2] == 3);
    CHECK(list3[3] == 4);
    CHECK(list3[4] == 5);
}