#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "OList.h"

TEST_CASE("insert and get")
{
    OList* l = new OList;
    l -> insert("b");
    l -> insert(1, "c");
    l -> insert("a");
    CHECK(l -> length() == 3);
    CHECK(l -> get(0) == "a");
    CHECK(l -> get(1) == "b");
    CHECK(l -> get(2) == "c");
}
TEST_CASE("contains")
{
    OList* l = new OList;
    l -> insert("a");
    l -> insert("b");
    l -> insert("c");
    CHECK(l -> contains("a"));
    CHECK(l -> contains("b"));
    CHECK(!(l -> contains("d")));
}
TEST_CASE("Remove")
{
    OList* l = new OList;
    l -> insert("a");
    l -> insert("b");
    l -> insert("c");
    CHECK(l -> length() == 3);
    l -> remove(1);
    CHECK(l -> length() == 2);
}
TEST_CASE("Reverse")
{
    OList* l = new OList;
    l -> insert("a");
    l -> insert("b");
    l -> insert("c");
    l -> reverse();
    CHECK(l -> get(0) == "a");
    CHECK(l -> get(1) == "b");
    CHECK(l -> get(2) == "c");
}
TEST_CASE("Destructor")
{
    OList* l = new OList;
    l -> insert("a");
    l -> insert("b");
    l -> insert("c");

    delete l;
    l = nullptr;
    CHECK(l == nullptr);
}