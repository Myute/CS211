#include <iostream>

using namespace std;

int multiply(int val1, int val2);

int main()
{
  int n1, n2;
  cout << "Enter a number: ";
  cin >> n1;
  cout << "Enter another number: ";
  cin >> n2;

  cout << n1 << " * " << n2 << " = " << multiply(n1, n2) << endl;
  return 0;
}

int multiply(int val1, int val2)
{
  if(val1 == 0)
    return 0;
  else
    return val2 + multiply(val1-1, val2);
}