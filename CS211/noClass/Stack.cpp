#include <iostream>

using namespace std;

#define MAX 5

class Stack
{
private:
  //const int MAX = 5;
  char letters[MAX];
  int top;
public:
  Stack();
  void push(char);
  void pop(char&);
  bool isEmpty();
  bool isFull();
  void displayAll();
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
  s.pop(c);
  cout << endl << " stack contents after popping 3 more elements: "
       << endl;
  s.displayAll();
  s.pop(c);
  s.push('a');
  s.push('b');
  cout << endl << " final stack contents" << endl;
  s.displayAll();
  return 0;
}

Stack::Stack()
{
  top = -1;
}
void Stack::push(char c)
{
  if(!isFull())
    letters[++top] = c;
  else
    cout << "Stack is Full, cannot push " << c << endl;
}
void Stack::pop(char& ch)
{
  if(!isEmpty())
    ch  = letters[top--];
  else
  cout << "ERROR: Cannot pop because stack is empty" << endl;
}
bool Stack::isEmpty()
{
  if(top == -1)
    return true;
  return false;
}
bool Stack::isFull()
{
  if(top >= MAX-1)
    return true;
  return false;
}
void Stack::displayAll()
{
  int tmp = top;
  if(isEmpty())
    cout << "Stack is Empty" << endl;
  else
    while(tmp != -1)
      cout << letters[tmp--]<< endl;
}
