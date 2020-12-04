/**
 * Assignment - Homework 5, Problem 2
 * Class - Queue.cpp
 * Author - Kevyn Higbee
 * Date Due - 5/7/18
 */

#include "Queue.h"
#include <iostream>

using namespace std;

/**
 * Class Constructor
 */
Queue::Queue()
{
  head = NULL;
  tail = NULL;
}
/**
 * Class Destructor
 */
Queue::~Queue()
{
  destroy();
}
/**
 * inserts an element into the end of the queue
 */
void Queue::enqueue(char elm)
{
  if(isEmpty())
    {
      head = new Node{elm, NULL};
      tail = head;
    }
  else
    {
      tail -> next = new Node{elm, NULL};
      tail = tail -> next;
    }
}
/**
 * returns and removes the head element of the queue
 */
void Queue::dequeue(char& c)
{
  Node *tmp = head;
  if(!isEmpty())
    {
      c = head -> val;
      head = head -> next;
      delete tmp;
    }
  else
    cout << "Cannot dequeue because queue is empty" << endl;
}
/**
 * displays all the contents of the queue
 */
void Queue::displayAll() const
{
  Node *tmp = head;
  if(isEmpty())
    cout << "Queue is Empty" << endl;
  else
    while(tmp)
      {
	cout << tmp -> val << " ";
	tmp = tmp -> next;
      }
  cout << endl;
}
/**
 * returns true if queue is empty else returns false 
 */
bool Queue::isEmpty() const
{
  if(head == NULL || tail == NULL)
    return true;
  return false;
}
/**
 * frees all elements of queue
 */ 
void Queue::destroy()
{
  char tmp;
  while(!isEmpty())
    dequeue(tmp);
}
