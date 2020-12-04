#include "RationalNumber.h"
#include <iostream>

using namespace std;

void printNum(const RationalNumber&);

int main()
{
  RationalNumber r1(7,3), r2(3,9), r3;
  r3 = r1 - r2;

  cout << "R1: ";
  printNum(r1);
  cout << endl << "R2: ";
  printNum(r2);
  cout << endl << "R1 - R2: ";
  printNum(r3);
  cout << endl;
  return 0;
}

void printNum(const RationalNumber& r)
{
  cout << r.numerator << "/" << r.denominator;
}
