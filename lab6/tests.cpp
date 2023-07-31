#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "BSTree.h"
#include <iostream>

TEST_CASE("Rsearch")
{
    BSTree* t = new BSTree();
    t -> insert(0);
    t -> insert(1);
    t -> insert(2);
    t -> insert(10);
    CHECK(t -> rsearch(1) == 1);
    CHECK(t -> rsearch(2) == 2);
    CHECK(t -> rsearch(10) == 10);
    bool work = true;
    try{
        t -> rsearch(1000);
    }
    catch(int e){
        work = false;
    }
    CHECK(work == false);
}

TEST_CASE("Delete")
{
BSTree* test = new BSTree();    
    BSTree *t = new BSTree();
    t->setup();
    //No Child
    t->remove(30);
    CHECK(t->get_debug_string() == ", 3, , 5, , 8, , 10, , 15, , 20, ");
    //One Child
    t->remove(20);
    CHECK(t->get_debug_string() == ", 3, , 5, , 8, , 10, , 15, ");
    t->insert(20);
    t->remove(15);
    CHECK(t->get_debug_string() == ", 3, , 5, , 8, , 10, , 20, ");
    t->insert(11);
    t->remove(20);
    CHECK(t->get_debug_string() == ", 3, , 5, , 8, , 10, , 11, ");
    //Two Child
    t->remove(10);
    CHECK(t->get_debug_string() == ", 3, , 5, , 8, , 11, ");
}

TEST_CASE("Height")
{
    BSTree* h = new BSTree();
    for(int i = 0; i < 10; i++)
    {
        h -> insert(i);
    }
    CHECK(h->height() == 10);
    BSTree* t = new BSTree();
    t -> setup();
    CHECK(t->height() == 3);
    t -> insert(2);
    CHECK(t->height() == 4);
    t -> insert(4);
    CHECK(t->height() == 4); 
}

TEST_CASE("Leaves")
{
    BSTree* t = new BSTree();
    t -> setup();
    CHECK(t -> leaves() == 4);
    t -> insert(2);
    CHECK(t -> leaves() == 4);
    t -> insert(4);
    CHECK(t -> leaves() == 5);
    t -> insert(21);
    t -> insert(31);
    CHECK(t -> leaves() == 6);
}