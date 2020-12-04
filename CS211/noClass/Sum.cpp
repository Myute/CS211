#include <iostream>

using namespace std;

int sum(int);

int main()
{

  int input;
  cin >> input;
  cout << sum(input) << endl;

  return 0;
}

int sum(int val) // what are we actually counting as steps???
{
  int sum = 0; // one step
  int iterations = 0;
  while(val != 0) // one step for comparison
    {
      sum+=(val%10); // 2 steps 1 - assignment addition to sum, 1 - val%10
      val/=10;       // 1 step - val/=10
      iterations++;
    }
  cout << endl << iterations << endl;
  return sum; // one step to return
}

// O(n) = 2n+2  => O(n)                                 (>_<)
