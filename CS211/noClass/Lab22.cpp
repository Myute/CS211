#include <iostream>

using namespace std;

class Stack
{
private: 
  struct StackNode
  {
    char element;
    StackNode *next;
  };
  
  StackNode* top;

public:
  Stack() { top = NULL; }
  ~Stack();
  void push(char);
  void pop(char&);
  void peek_top(char&) const;
  void displayAll() const;
  bool isEmpty() const;
};

int main()
{
  Stack s;
  char c;
  cout << " initial stack contents" << endl;
  s.displayAll();
  s.pop(c);
  s.push('a');
  cout << endl << " stack contents after pushing a: " << endl;
  s.displayAll();
  s.push('b');
  cout << endl << " stack contents after pushing b: " << endl;
  s.displayAll(); 

  s.push('c');
  s.push('d');
  s.push('e');
  s.push('f');
  s.push('g');
  cout << endl << " stack contents after pushing c-g: " << endl;
  s.displayAll();
  s.peek_top(c);
  cout << endl << "top elment is " << c << endl;
  s.pop(c);
  cout << endl << c << endl;
  cout << endl << " stack contents after popping one element: "
       << endl;
  s.displayAll();
  s.pop(c);
  cout << endl << " popped element: " << c << endl;
  cout << endl << " stack contents after popping another element: "
       << endl;
  s.displayAll();
  s.pop(c);
  s.pop(c);
  if (!s.isEmpty())
    {
      s.peek_top(c);
      cout << endl << "top elment is " << c << endl;
    }
  s.pop(c);
  cout << endl << " stack contents after popping 3 more elements: "
       << endl;
  s.displayAll();
  s.pop(c);
  s.pop(c);
  s.push('a');
  s.push('b');
  cout << endl << " final stack contents " << endl;
  s.displayAll(); 
  return 0;
}

Stack::~Stack()
{
  char c;
  while(!isEmpty())
    pop(c);
}
void Stack::push(char c)
{
  StackNode *node = new StackNode;
  node -> element = c;
  if(top)
    {
      node -> next = top;
      top = node;
    }
  else
    top = node;
}
void Stack::pop(char& c)
{
  StackNode *old;
  if(isEmpty())
    c = '-';
  else
    {
      c = top -> element;
      old = top;
      top = top -> next;
      delete old;
    }
}
void Stack::peek_top(char& c) const
{
  c = top -> element;
}
void Stack::displayAll() const
{
  StackNode *tmp = top;
  if(!tmp)
    cout << "Stack is Empty" << endl;
  else
    while(tmp)
      {
	cout <<  tmp -> element << endl;
	tmp = tmp -> next;
      }
}
bool Stack::isEmpty() const
{
  if(top)
    return false;
  else
    return true;
}