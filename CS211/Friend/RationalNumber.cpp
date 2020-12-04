#include "RationalNumber.h"

RationalNumber::RationalNumber(int n, int d)
{
  numerator = n;
  denominator = d;
};
RationalNumber::RationalNumber()
{
  numerator = 0;
  denominator = 1;
}
RationalNumber RationalNumber::operator-(const RationalNumber& r1)
{
  RationalNumber r2((numerator*r1.denominator)-(r1.numerator*denominator),r1.denominator*denominator);
  return r2;
}