#include <iostream>

using namespace std;

#define MAX 5
typedef char el_t;

class Queue
{
private:
  int count, front, rear;
  el_t el[MAX];
public:
  Queue();
  void enqueue(el_t);
  void dequeue(el_t&);
  void displayAll() const;
  bool isEmpty() const;
  bool isFull() const;
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
  cout << endl << " Queue contents after removing one element: " << endl;
  q.displayAll();
  q.dequeue(c);
  cout << endl << " Removed element: " << c << endl;
  cout << endl << " Queue contents after removing another element: " << endl;
  q.displayAll();
  q.enqueue('g');
  q.enqueue('h');
  q.enqueue('i');
  cout << endl << " Queue contents after adding g, h, i: " << endl;
  q.displayAll();
  q.dequeue(c);
  q.dequeue(c);
  q.dequeue(c);
  q.dequeue(c);
  cout << endl << " Queue contents after removing 4 elements: " << endl;
  q.dequeue(c);
  q.dequeue(c);
  cout << endl << " final Queue contents " << endl;
  q.displayAll(); 
  return 0;
}

Queue::Queue()
{
  count = 0;
  front = 0;
  rear = -1;
}
void Queue::dequeue(el_t& element)
{
  if(!isEmpty())
    {
      element = el[front];
      front = (front + 1) % MAX;
      count-=1;
    }
  else
    cout << "ERROR: Cannot dequeue because queue is empty" << endl;
}
void Queue::enqueue(el_t element)
{
  if(!isFull())
    {
      rear = (rear+1)%MAX;
      el[rear] = element;
      count++;
    }
  else
    cout << "ERROR: Queue is full" << endl;
}
void Queue::displayAll() const
{
  int tmp = front;
  if(!isEmpty())
    {
      for(int i = 0; i < count; i++)
	{
	  if(tmp == MAX)
	    tmp = 0;
	  cout << el[tmp++] << " " << endl;
        }
      cout << endl;
    }
  else
    cout << "Queue is empty" << endl;
  cout << endl;
}
bool Queue::isFull() const
{
  if(count == MAX)
    return true;
  return false;
}
bool Queue::isEmpty() const
{
  if(count == 0)
    return true;
  return false;
}
