#include <iostream>

using namespace std;

struct List
{
  double val;
  List *nextPtr = NULL;
};

int main()
{
  double sum = 0, avg = 0;
  int size = 0;
  List startPtr;
  List *currentPtr = &startPtr;
  List *prevPtr = NULL;

  // read size from user
  cout << "Enter the number of monthly sales to be input: ";
  cin >> size;

  // read values from user
  for(int i = 1; i <= size; i++)
    {
      cout << "Enter the monthly sales for month " << i << ": $ ";
      cin >> currentPtr -> val;

      currentPtr -> nextPtr = new List;
      currentPtr = currentPtr -> nextPtr;
    }

  // add values
  currentPtr = &startPtr;
  while(currentPtr)
    {
      sum += currentPtr -> val;
      currentPtr = currentPtr -> nextPtr;
    }
  // print total and average
  avg = sum / size;
  cout << "The total sales for the year is: $ " << sum << endl
       << "The average monthly sale is: $ " << avg << endl;

  // deallocate memory
  currentPtr = startPtr;
  prevPtr = &startPtr;
  while(currentPtr -> nextPtr)
    {
      delete currentPtr;
      
    }
  return 0;
}
