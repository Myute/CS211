/**
 * Assignment - Homework 5, Problem 1
 * Class - Driver.cpp
 * Author - Kevyn Higbee
 * Date Due - 5/7/18
 */

#include <iostream>
#include "Stack.h"
#include <string>

using namespace std;

/**
 * returns if the string is properly balanced
 */
bool properlyBalanced(string);
/**
 * comapres the stacks values
 */
bool checkStack(Stack&, string);


/**
 * Main
 * gets user input through loop and checks input
 */
int main()
{
  string str;
  
  do
    {
      cout << "Enter a String: " << endl;
      getline(cin, str);
      if(str != "Q" && str != "q")
	if(properlyBalanced(str))
	  cout << "This string is properly balanced" << endl;
	else
	  cout << "This string is not properly balanced" << endl;
    }
  while(str != "Q" && str != "q");

  return 0;
}

/**
 * returns if string is properly balanced
 */
bool properlyBalanced(string str)
{
  Stack stack;
  return checkStack(stack,str);
}
/**
 * checks the strings balance using passed stack
 */
bool checkStack(Stack& stack, string str)
{
  char c, c2;

  for(int i = 0; i < str.length(); i++)
    {
      c = str[i];
      // inspect first delimiter
      if(c == '(' || c == '{' || c == '[')
	stack.push(c);
      else
	// find corresponging delimiter
	if(c == ')' || c == '}' || c == ']')
	  {
	    stack.peek_top(c2);
	    
	    if(c2 == '-')
	    {
	      cout << "Extra Right Delimiter" << endl;
	      return false;
	    }
	    if(c == ')' && c2 == '(')
	      stack.pop(c2);
	    else
	      if(c == '}' && c2 == '{')
		stack.pop(c2);
	      else
		if(c == ']' && c2 == '[')
		  stack.pop(c2);
		else
		  cout << "Delimiter Mismatch" << endl;
	  } 
    }
  // if when done popping stack is not empty
  if(!stack.isEmpty())
    cout << "Missing Right Delimiter" << endl;
  return stack.isEmpty();
}
