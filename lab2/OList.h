#pragma once
#include <iostream>
#include "Node.h"
#include <string>

class OList{
    private:
        Node *head;

    public:
        OList();
        ~OList();
        void insert(std::string data);
        void insert(int loc, std::string data);
        std::string toString();
        bool contains(std::string data);
        std::string get(int loc);
        void remove(int loc);
        void reverse();
        int length();
};