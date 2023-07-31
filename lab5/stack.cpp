#include "stack.h"
#include "Node.h"
#include <iostream>

Stack::Stack()
{
    head = nullptr;
}

Stack::Stack(int i)
{
    head = new Node(i);
}

Stack::~Stack()
{
    Node *walker, *trailer;
    walker = this->head;
    trailer = nullptr;
    while(walker != nullptr){
        trailer = walker;
        walker = walker -> getNext();
        delete trailer;
    }
}

void Stack::push(int x)
{
    Node* tmp = new Node(x);
    tmp -> setNext(head);
    head = tmp;
}

int Stack::pop()
{
    if(head == nullptr)//Checks if Stack is empty
    { 
        throw STACK_ERR_EMPTY;
    }
    int data = head -> getData();
    head = head -> getNext();
    return data;
}

int Stack::top()
{
    if(head == nullptr) //Checks if Stack is empty
    {
        throw STACK_ERR_EMPTY;
    }
    return head -> getData();
}

bool Stack::is_empty()
{
    if(head == nullptr)
    {
        return true;
    }
    return false;
}