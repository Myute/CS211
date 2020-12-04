#define NODE_H
#ifndef NODE_H

#include <iostream>

class Node
{
 private:
  string firstName;
  string lastName;
  string phoneNumber;
  Node* next;

 public:
  Node* getNext();
  string getFirst();
  string getLast();
  string getPhoneNum();
};
