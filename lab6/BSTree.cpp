#include <iostream>
#include "Node.h"
#include "BSTree.h"

BSTree::BSTree(){
  root = nullptr;
}

std::string BSTree::traverse(Node *n){
  std::string a,b,c;
  
  if (n==nullptr){
    return "";
  } else {
    a = traverse(n->getLeft());
    b = std::to_string(n->getData());
    c = traverse(n->getRight());
    return a + ", " + b+ ", " + c; 
  }
}

std::string BSTree::get_debug_string(){
  return traverse(root);
}
/*
int BSTree::search(int n){
  Node *current = root;

  
  while (current != nullptr){
    int node_val = current->getData();
    if (n == node_val){
      return node_val;
    } else if (n < node_val){
      current = current->getLeft();
    } else {
      current = current->getRight();
    }
  }
  throw 1; // returning a not found value would be better
}
*/

void BSTree::insert(int n){
  Node *new_node = new Node(n);

  // special case if the tree is empty
  if (root == nullptr){
    root = new_node;
    return;
  }

  // search for the insertion point
  Node *current = root;
  Node *trailer = nullptr;
  while (current != nullptr){
    trailer = current; // catch the trailer up
    int val = current->getData();
    if (n == val){
      // update the node with the additional stuff
      return;
    } else if (n < val){
      current = current->getLeft();
    } else {
      current = current->getRight();
    }
  }
  // if we get here, trailer points to the
  // node above the new node's location
  if (n < trailer->getData()){
    trailer->setLeft(new_node);
  } else {
    trailer->setRight(new_node);
  }    
}

int BSTree::rsearch(int value)
{
    return rsearch(value, root);
}

int BSTree::rsearch(int value, Node *p)
{
    //Sees if tree is empty
    if(p == nullptr)
    {
        throw EMPTY_TREE;
    }
    //If given node is the one, return its value
    if(p -> getData() == value)
    {
        return value;
    }
    //Search left if delNode is less than current value, else search right
    if(p -> getData() > value)
    {
        return rsearch(value, p -> getLeft());
    }
    else
    {
        return rsearch(value, p -> getRight());
    }
}

//To decide which case in delete should execute
int BSTree::numChildren(Node* n)
{
  int count = 0;
  if(n -> getLeft() != nullptr)
  {
    count++;
  }
  if(n -> getRight() != nullptr)
  {
    count++;
  }
  return count;
}

Node* BSTree::searchNode(int value)
{
  Node* current = root;
  while(current != nullptr)
  {
    int current_val = current->getData();
    if(value == current_val)
    {
      return current;
    }
    else if(value > current_val)
    {
      current = current -> getRight();
    }
    else
    {
      current = current -> getLeft();
    }
  }
  return nullptr;
}

int BSTree::minValue(Node *n)
{
  int tmp = n -> getData();
  while(n -> getLeft() != nullptr)
  {
    tmp = n -> getLeft() -> getData();
    n = n -> getLeft();
  }
  return tmp;
}

int BSTree::minValue()
{
  return minValue(root);
}

int BSTree::height(Node *n)
{
  if(n == nullptr)
  {
    return 0;
  }
  int leftHeight = height(n -> getLeft());
  int rightHeight = height(n -> getRight());
  if(rightHeight > leftHeight)
  {
    return (rightHeight + 1);
  }
  else
  {
    return (leftHeight + 1);
  }
}

int BSTree::height()
{
  return height(root);
}

int BSTree::leaves(Node *n)
{
  if(n == nullptr)
  {
    return 0;
  }
  else if(n->getLeft() == nullptr && n->getRight() == nullptr)
  {
    return 1;
  }
  else
  {
    return leaves(n -> getLeft()) + leaves(n -> getRight());
  }
}

int BSTree::leaves()
{
  return leaves(root);
}
void BSTree::remove(int value)
{
  Node *current = root;
  Node *trailer = nullptr;
  if(current == nullptr)
  {
    throw EMPTY_TREE;
  }

  //Finds the node that will get deleted, and leaves the trailer one node behind it
  while(current -> getData() != value)
  {
    if(current == nullptr)
    {
      throw EMPTY_TREE;
    } else if(value > current->getData())
    {
      trailer = current;
      current = current -> getRight();
    } else if(value < current->getData())
    {
      trailer = current;
      current = current -> getLeft();
    }
  }
  int children = numChildren(current);
  //Case 1: No Child
  if(children == 0)
  {
    if(value > trailer -> getData())
    {
      trailer -> setRight(nullptr);
    }
    else
    {
      trailer -> setLeft(nullptr);
    }
  }else if(children == 1) //Case 2: One Child
  {
    if(trailer -> getRight() == current)
    {
      if(current->getLeft() == nullptr)
      {
        trailer -> setRight(current -> getRight());
      }
      else
      {
        trailer -> setRight(current -> getLeft());
      }
    }else if(trailer -> getLeft() == current)
    {
      if(current -> getRight() == nullptr)
      {
        trailer -> setLeft(current -> getLeft());
      }
      else
      {
        trailer -> setLeft(current -> getRight());
      }
    }
  }else if(children == 2) //Case 3: Two Children
  {
    int minVal = minValue(current->getRight());
    Node *tmp = searchNode(minVal);
    int value = tmp->getData();
    remove(value);
    current->setData(value);
  }
}

void BSTree::setup(){
  Node *n = new Node(10);
  root = n;
  n = new Node(20);
  root->setRight(n);
  Node *n2 = new Node(30);
  n->setRight(n2);
  n2 = new Node(15);
  n->setLeft(n2);
  n2 = new Node(5);
  root->setLeft(n2);
  n = new Node(3);
  n2->setLeft(n);
  n = new Node(8);
  n2->setRight(n);
}