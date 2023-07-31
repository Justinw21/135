#pragma once
#include <iostream>
#include "Node.h"
#include "Person.h"
#include <string>

class List{
  private:
    Node *head;
  public:
    List();
    ~List();  
    void insert(Person data);
    void insert(int loc, Person data); //0 indexed
    int length();
    std::string toString(); // for testing purposes
    Person get(std::string fname, std::string lname);
    Node* contains(Person item);
    void remove(int loc);
};