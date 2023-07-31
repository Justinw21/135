#include <iostream>
#include "OList.h"
#include <string>

OList::OList()
{
    head = nullptr;
}

OList::~OList()
{
    Node* walker = head;
    Node* trailer = nullptr;
    while(walker != nullptr)
    {
        trailer = walker;
        walker = walker->getNext();
        delete trailer;
    }
}

void OList::insert(std::string data){
    Node *tmp = new Node(data);
    tmp->setNext(head);
    head = tmp;
}

void OList::insert(int loc, std::string data){
  Node *walker, *trailer;
  walker = this->head; // start of the list
  trailer = nullptr; // one behind
  
  while(loc>0 && walker != nullptr){
    loc=loc-1;
    trailer=walker;
    walker = walker->getNext();
    
  }
  if (loc > 0){
    throw std::out_of_range("Our insert is out of range");
  }

  Node *newNode = new Node(data);
  if (trailer == nullptr){
    newNode->setNext(head);
    head = newNode;
  } else {
    newNode->setNext(walker);
    trailer->setNext(newNode);
  }
}

std::string OList::toString(){
    Node *tmp = this->head;
    std::string result = "";
    while (tmp != nullptr){
        result = result + tmp->getData();
        result = result + "-->";
        tmp = tmp->getNext();
    }
    result = result + "nullptr";
    return result;
}

bool OList::contains(std::string item){
    Node *tmp = head;
    while(tmp!= nullptr){
        if(tmp->getData() == item)
        {
            return true;
        }
        tmp = tmp->getNext();
    }
    return false;
}

std::string OList::get(int loc){
    Node *walker = head;
    while(loc > 0 && walker != nullptr)
    {
        walker = walker -> getNext();
        loc--;
    }

    if(walker == nullptr)
    {
        return "invalid";
    }
    return walker -> getData();
}

void OList::remove(int loc){
    Node *walker, *trailer;
    walker = this->head; // start of the list
    trailer = nullptr; // one behind

    while(loc > 0  && walker != nullptr){
        loc=loc-1;
        trailer=walker;
        walker = walker->getNext();
    
    }
    if (walker == nullptr){
      throw std::out_of_range("Our remove is out of range");
    }

    if(trailer == nullptr){
      head = walker->getNext();
      delete walker;  
    } else {
    trailer->setNext(walker->getNext());   
    delete walker;
    }
}

void OList::reverse(){
    Node *walker = head;
    Node *trailer = nullptr;
    while(walker != nullptr)
    {
        Node* tmp = walker->getNext();
        walker->setNext(trailer);
        trailer = walker;
        walker = tmp;
    }
    head = trailer;
}

int OList::length(){
  int count = 0;
  Node *walker = head;
  while (walker != nullptr){
    count++;
    walker = walker->getNext();
  }
  return count;
}