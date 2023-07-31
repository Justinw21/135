#include <iostream>
#include "Dictionary.h"

int main(){

    Person p1("Justin", "Wong", 1);
    Person p2("James", "Wong", 1);
    Person p3("Jonathan", "Wong", 1);
    Person p4("Kam", "Wong", 1);
    Person p5("Alice", "Wong", 1);

    Dictionary* dict = new Dictionary();
    dict->insert(p1);
    dict->insert(p2);
    dict->insert(p3);
    std::cout << dict -> getKeys() << std::endl;
    dict->insert(p4);
    dict->insert(p5);
    std::cout << dict ->getKeys() << std::endl;
    Node* retrieved = dict -> retrieve(p1);
    std::cout << retrieved -> getData().get_name();

    delete dict;
    return 0;
}