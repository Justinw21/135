#include <iostream>
#include "Node.h"
#include "List.h"

//Constructor
List::List(){
  head = nullptr;
}

//Destructor
List::~List()
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
// insert at the "front" (head)
void List::insert(std::string data){
  Node *tmp = new Node(data);
  tmp->setNext(head);
  head = tmp;
}

/*
  insert at loc
*/
void List::insert(int loc, std::string data){
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


//Length of linked list
int List::length(){
  int count = 0;
  Node *walker = head;
  while (walker != nullptr){
    count++;
    walker = walker->getNext();
  }
  return count;
}

//Checks if linked list contains 
bool List::contains(std::string item){
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

void List::remove(int loc){
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

std::string List::toString(){
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