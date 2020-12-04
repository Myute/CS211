/**
 * Assignment - Homework 5, Problems 1 & 2
 * Class - Stack.h
 * Author - Kevyn Higbee
 * Date Due - 5/7/18
 */

#ifndef STACK_H
#define STACK_H

class Stack
{
 private:
  // element definition
  struct Node
  {
    char val;
    Node *next;
  };

  Node *top;  // top element of stack

 public:
  Stack();              // class constructor
  ~Stack();             // class destructor
  void peek_top(char&); // returns the top element without removing it
  void pop(char&);      // returns and removes the top element
  void push(char);      // pushes the passed element onto the stack
  void destroy();       // freees all memory being used by this object
  void displayAll() const;    // displys all contents of stack
  bool isEmpty() const; // returns if the stack is empty or not
};

#endif
