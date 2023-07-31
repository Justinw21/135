#pragma once
#include "List.h"

class Dictionary{
    private:
        List *list[101];
    
    public:
        Dictionary();
        ~Dictionary();
        int sfold(std::string s);
        void insert(Person p);
        Node* retrieve(Person p);
        std::string getKeys();
};