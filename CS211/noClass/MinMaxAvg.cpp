#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

void minMaxAvg(int a, int b, int c, int& min, int& max, float& avg);

int main()
{
  int a, b, c, min, max;
  float avg;
  // get user input
  cout << "Please enter 3 numbers: ";
  cin >> a >> b >> c;

  // math stuff
  minMaxAvg(a,b,c,min,max,avg);
  
  // output
  cout << left << setw(20) << "The average is:" << right << fixed << showpoint << setprecision(2) << setw(5) << avg << endl
       << left << setw(20) << "The min is:" << right << setw(5) << min << endl
       << left << setw(20) << "The max is:" << right << setw(5) << max << endl;

  return 0;
}

void minMaxAvg(int a, int b, int c, int& min, int& max, float& avg)
{
  int sum;
  // get min
  if(a <= b && a <= c)
    min = a;
  if(b <= a && b <= c)
    min = b;
  if(c <= a && c <= b)
    min = c;
  // get max
  if(a >= b && a >= c)
    max = a;
  if(b >= a && b >= c)
    max = b;
  if(c >= a && c >= b)
    max = c;
  // get mean average
  sum = a + b + c;
  avg = sum / 3.0;
}
