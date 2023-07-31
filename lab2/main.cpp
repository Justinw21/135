#include <iostream>
#include "List.h"
#include "OList.h"

int main()
{
  /*
    List *l = new List();
    std::cout << l->toString() << " " << l->length() << "\n";

    //Both inserts, toString, and length
    l->insert("a");
    std::cout << l->toString() << " " << l->length() << "\n";
    l->insert("c");
    l->insert(1,"b");
    l->insert("d");
    std::cout << l->toString() << " " << l->length() << "\n";

    //Contains
    std::cout << l->contains("a") << "\n"; // 1
    std::cout << l->contains("b") << "\n"; // 1
    std::cout << l->contains("c") << "\n"; // 1
    std::cout << l->contains("d") << "\n"; // 1
    std::cout << l->contains("e") << "\n"; // 0
    
    //Remove
    l->remove(3);
    std::cout << l->toString() << " " << l->length() << "\n";
    */
    OList *l = new OList();
    l->insert("e");
    l->insert("d");
    l->insert("c");
    l->insert("b"); 
    l->insert("a");

    std::cout << "toString" << "\n";
    std::cout << l -> toString() << "\n\n";

    std::cout << "Contains a,b,c,e respectively" << "\n";
    std::cout << l -> contains("a") << "\n" << l-> contains("b") << "\n" << l -> contains("c") << "\n" << l -> contains("e") << "\n";

    std::cout << "get" << "\n";
    std::cout << "Data at 2 = " << l -> get(2) << "\n";

    std::cout << "remove data at 2\n";
    l->remove(2);
    std::cout << l->toString() << "\n";
    
    std::cout << "reversing list\n";
    l->reverse();
    std::cout << l->toString() << "\n"; 

    std::cout << "calling destructor\n";
    delete l;
  }