#include <iostream>
#include <string>

using namespace std;

/************************************ NODE DEFINITION ********************************************/
class Node
{
  friend class LinkedList;

private:
  string first;
  string last;
  string phone;
  Node* next;

public:
  Node(string f, string l, string p);
};

/**************************************** LL DEFINITION *****************************************/
class LinkedList
{
private:
  Node* head;
  void destroy();
public:
  LinkedList();
  LinkedList(const LinkedList& list);
  ~LinkedList();
  void removeRecord(string f, string l);
  void append(string f, string l, string p);
  void insertAtHead(string f, string l, string p);
  void insertAtPos(string f, string l, string p, int pos);
  void searchByName(string f, string l);
  void updateNumber(string f, string l, string p);
  void print();
};
/******************************** MAIN FUNCTION *****************************************/
int main()
{
  LinkedList list1;
 
  list1.append ("Mayssaa", "Najjar", "878-635-1234");
  list1.insertAtHead ("Jim", "Meyer", "337-465-2345");
  list1.append ("Joe", "Didier", "352-654-1983");
  list1.insertAtPos ("Adam", "James", "202-872-1010", 2);
  list1.insertAtHead("Nancy", "Garcia", "617-227-5454");

  list1.print();

  cout << endl;

  list1.removeRecord ("Mayssaa", "Najjar");
  cout << endl;

  list1.removeRecord ("Jamie", "Najjar");
  cout << endl;

  list1.print();

  cout << endl;

  LinkedList list2(list1);
  list2.print();

 
  return 0;
}

/******************************* LINKED LIST FUNCTIONS**************************************/
LinkedList::LinkedList()
{
  head = NULL;
}
void LinkedList::append(string f, string l, string p)
{
  Node* current = NULL;
  if(!head)
    insertAtHead(f, l, p);
  else
    {
      current = head;
      while(current -> next)
	current = current -> next;
      current -> next = new Node(f, l, p);
    }
}
void LinkedList::insertAtHead(string f, string l, string p)
{
  Node* oldHead = NULL;
  if(head)
    oldHead = head;
  head = new Node(f, l, p);
  if(head)
    head -> next = oldHead;
}
void LinkedList::insertAtPos(string f, string l, string p, int pos)
{
  Node* node = NULL;
  Node* current = NULL;
  Node*  prev = NULL;
  
  node = new Node(f,l,p);
  // case for if node is inserted at head
  if(pos == 1)
    {
      current = head;
      node -> next = current;
      head = node;
    }
  else
    {
      current = head;
      for(int i = 1; i < pos; i++)
	{
	  prev = current;
	  current = current -> next;
	}
      prev -> next = node;
      node -> next = current;
    }
}
void LinkedList::searchByName(string f, string l)
{
  Node* current = head;
  while(current && !(current -> first == f) && !(current -> last == l))
      current = current -> next;
  if(current && (current -> first == f) && (current -> last == l))
    cout << current -> first << " " << current -> last << ", " << current -> phone << endl;
  else
    cout << f << " " << l << " not found in list" << endl;
}
void LinkedList::updateNumber(string f, string l, string p)
{
  Node* current = head;
  while(current && !(current -> first == f) && !(current -> last == l))
    current = current -> next;
  if(current && (current -> first == f) && (current -> last == l))
    {
      current -> phone = p;
      cout << "Successfully updated " << f << " " << l << "'s phone number to " << p << endl;
    }
  else
    cout << f << " " << l << " was not found in the list" << endl;
}
void LinkedList::print()
{
  Node* current = head;
  cout << "List: " << endl;
  while(current)
    {
      cout << current -> first << " " << current -> last << ", " << current -> phone << endl;
      current = current -> next;
    }
}
LinkedList::~LinkedList()
{
  destroy();
}
void LinkedList::destroy()
{
  Node* nodeptr = head;
  Node* nextptr = NULL;
  
  while(nodeptr)
    {
      nextptr = nodeptr -> next;
      delete nodeptr;
      nodeptr = nextptr;
    }  
}
void LinkedList::removeRecord(string f, string l)
{
  Node* prev = NULL;
  Node* current = head;
  while(current && !(current -> first == f) && !(current -> last == l))
    {
      prev = current;
      current = current -> next;
    }
  if(current && (current -> first == f) && (current -> last == l))
    {
      // case if node is head
      if(!prev)
	{
	  head = current -> next;
	  delete current;
	}
      else
	{
	  prev -> next = current -> next;
	  delete current;
	}
      cout << "Successfully removed " << f << " " << l << " from list" << endl;
    }
  else
    cout << f << " " << l << " was not found in the list" << endl;
}
LinkedList::LinkedList(const LinkedList& list)
{
  Node* currentptr = list.head;

  while(currentptr)
    {
      append(currentptr -> first, currentptr -> last, currentptr -> phone);
      currentptr = currentptr -> next;
    }
  
}
/******************************* NODE FUNCTIONS ********************************************/
Node::Node(string f, string l, string p)
{
  first = f;
  last = l;
  phone = p;

  next = NULL;
}
