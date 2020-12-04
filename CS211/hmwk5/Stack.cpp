/**
 * Assignment - Homework 5, Problems 1 & 2
 * Class - Stack.cpp
 * Author - Kevyn Higbee
 * Date Due - 5/7/18
 */

#include "Stack.h"
#include <cstddef>
#include <iostream>

using namespace std;
/**
 * Class constructor
 */
Stack::Stack()
{
  top = NULL;
}
/**
 * Class destructor
 */
Stack::~Stack()
{
  destroy();
}
/**
 * frees all memory of this object
 */
void Stack::destroy()
{
  char tmp;
  while(!isEmpty())
    pop(tmp);
}
/**
 * pushes value onto stack
 */
void Stack::push(char c)
{
  Node *tmp = new Node;
  tmp -> val = c;
  if(top)
    {
      tmp -> next = top;
      top = tmp;
    }
  else
    top = tmp;
}
/**
 * pops the top element
 */
void Stack::pop(char& c)
{
  Node *old;
  if(isEmpty())
    c = '-';
  else
    {
      c = top -> val;
      old = top;
      top = top -> next;
      delete old;
    }
}
/**
 * returns the top element without removing it
 */
void Stack::peek_top(char& c)
{
  if(!isEmpty())
    c = top -> val;
  else
    c = '-';
}
/**
 * displays every element
 */ 
void Stack::displayAll() const
{
  Node *tmp = top;
  if(!tmp)
    std::cout << "Stack is Empty" << endl;
  else
    while(tmp)
      {
	std::cout << tmp -> val << endl;
	tmp = tmp -> next;
      }
}
/**
 * returns if stack is empty or not
 */
bool Stack::isEmpty() const
{
  if(top)
    return false;
  else
    return true;
}
