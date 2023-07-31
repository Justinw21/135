#include <iostream>
#include "Node.h"
#include "BSTree.h"
int main()
{

    BSTree *t = new BSTree();
    t->setup();

    std::cout <<  t->get_debug_string() << "\n";
    //research and insert
    int n;
    n = t->rsearch(10);
    std::cout << "found " << n << "\n";
    n = t->rsearch(8);
    std::cout << "found " << n << "\n";
    n = t->rsearch(15);
    std::cout << "found " << n << "\n";
    try {
    n = t->rsearch(17);
    std::cout << "found " << n << "\n";
    } catch (int e){
        std::cout << 17 << " not found\n";
    }
    t->insert(17);
    n = t->rsearch(17);

    std::cout << t->get_debug_string() << "\n";
    std::cout << "found " << n << "\n";
    Node* tmp = t->searchNode(10);
    std::cout << "minimum value = " << t->minValue(tmp) << "\n";
    std::cout << "height of tree = " << t->height() << "\n";
    std::cout << "number of leaves = " <<  t->leaves() << "\n";
    t->remove(30);
    t->remove(20);
    t->remove(10);
    std::cout << t->get_debug_string() << "\n";

    BSTree *t2 = new BSTree();
    std::cout << t2->height() << "\n";
    for(int i = 0; i < 10; i++)
    {
        t2 -> insert(i);
    }
    std::cout << t2->height() << "\n";

    std::cout << t->get_debug_string() << "\n";
    return 0;
}