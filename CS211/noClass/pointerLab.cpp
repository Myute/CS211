#include <iostream>

using namespace std;

int main()
{
  int result;
  int *one = NULL;
  int *two = NULL;
  int *three = NULL;
  
  // allocate the integer variables one, two, three
  // input three numbers and store them in the dynamic variables
  // pointed to by pointers one, two, three
  one = new int;
  two = new int;
  three = new int;

  cout << "Enter three numbers: ";
  cin >> *one >> *two >> *three;

  // calculate the sum of the three numbers, store it in result,
  // then output those three numbers and their sum
  result = (*one) + (*two) + (*three);
  cout << *one << " + " << *two << " + " << *three << " = " << result<< endl;

  // deallocate one, two, and three
  delete one;
  delete two;
  delete three;

  return 0;
}
