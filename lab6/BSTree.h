#pragma once
#include <iostream>
#include <stdio.h>
#include "Node.h"
#define EMPTY_TREE 1

class BSTree{
 private:
  Node *root;
  std::string traverse(Node *n);

public:
  BSTree();
  void setup();
  std::string get_debug_string();
  
  
  //int search(int value);
  void insert(int value);
  int rsearch(int value);
  int rsearch(int value, Node *p);
  int numChildren(Node *n);
  Node* searchNode(int value);
  int minValue(Node *n);
  int minValue();
  int height(Node *n);
  int height();
  int leaves(Node *n);
  int leaves();
  void remove(int value);
};