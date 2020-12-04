#include <iostream>

using namespace std;

typedef char el_t;

class Queue
{
  private:
     struct Node
     {
       el_t val;
       Node *next;
     };

     Node *head;
     Node *tail;
  public:
     Queue();
     ~Queue();
     void enqueue(el_t);
     void dequeue(el_t&);
     void displayAll() const;
     bool isEmpty() const;
};

int main()
{
  Queue q;
  el_t c;
  cout << " initial Queue contents" << endl;
  q.displayAll();
  q.dequeue(c);
  q.enqueue('a');
  cout << endl << " Queue contents after adding a: " << endl;
  q.displayAll();
  q.enqueue('b');
  q.enqueue('c');
  q.enqueue('d');
  q.enqueue('e');
  q.enqueue('f');
  cout << endl << " Queue contents after adding b-f: " << endl;
  q.displayAll();
  q.dequeue(c);
  cout << endl << c << endl;
  cout << endl << " Queue contents after removing one element: "
       << endl;
  q.displayAll();
  q.dequeue(c);
  cout << endl << " Removed element: " << c << endl;
  cout << endl << " Queue contents after removing another element: "
       << endl;
  q.displayAll();
  q.enqueue('g');
  q.enqueue('h');
  q.enqueue('i');
  cout << endl << " Queue contents after adding g, h, i: "
       << endl;
  q.displayAll();
  q.dequeue(c);
  q.dequeue(c);
  q.dequeue(c);
  q.dequeue(c);
  cout << endl << " Queue contents after removing 4 elements: "
       << endl;
  q.dequeue(c);
  q.dequeue(c);
  cout << endl << " final Queue contents " << endl;
  q.displayAll();
  return 0;
}
Queue::Queue()
{
  head = NULL;
  tail = NULL;
}
Queue::~Queue()
{
  char tmp;
  while(!isEmpty())
    dequeue(tmp);
}
void Queue::enqueue(el_t elm)
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
void Queue::dequeue(el_t& elm)
{
  Node *tmp = head;
  if(!isEmpty())
    {
      elm = head -> val;
      cout << "Removing: " << elm << endl;
      head = head -> next;
      delete tmp;
    }
  else
    cout << "Cannot dequeue because queue is empty" << endl;
}
void Queue::displayAll() const
{
  Node *tmp = head;
  if(isEmpty())
    cout << "Queue is empty";
  else
    while(tmp)
      {
	cout << tmp -> val << " ";
	tmp = tmp -> next;
      }
  cout << endl;
}
bool Queue::isEmpty() const
{
  if(head == NULL || tail == NULL)
    return true;
  return false;
}
