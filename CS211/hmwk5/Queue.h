/**
 * Assignment - Homework 5, Problem 2
 * Class - Queue.h
 * Author - Kevyn Higbee
 * Date Due - 5/7/18
 */

#ifndef QUEUE_H
#define QUEUE_H

class Queue
{
 private:
  // Node element definition
  struct Node
  {
    char val;
    Node *next;
  };
 
  Node *head;  // head element
  Node *tail;  // tail element
 
 public:
  Queue();                  // class constructor
  ~Queue();                 // class destructor
  void enqueue(char);       // adds an element to the queue
  void dequeue(char&);      // removes and returns the head element
  void destroy();           // frees all the memory used by queue
  void displayAll() const;  // displays every element
  bool isEmpty() const;     // returns if the queue has any contents
};

#endif
