#include <iostream>
#include <string>
#include <iomanip>

#include <math.h>

using namespace std;

// CLASS DEFINITION
class Mortgage
{
private:
  double loanAmount;
  double rate;
  int years;
public:
  void set(double, double, int);
  void print();
  double calcMonthly();
};
  // CLASS FUNCTION DEFINITIONS
  void Mortgage::set(double l, double r, int y)
  {
    loanAmount = l;
    rate = r;
    years = y;
  }
  void Mortgage::print()
  {
    cout << "\nPrinting Loan Summary Information:\nLoanAmount: $" << fixed << showpoint << setprecision(2) << loanAmount << endl
	 << "Interest Rate: " << (rate*100) << "%" << endl
	 << "Loan Period: " << years << " years" << endl;
  }
  double Mortgage::calcMonthly()
  {
    double term = pow(1 + (rate/12), 12 * years);
    return ((loanAmount * term * (rate/12)) / (term-1));
  }
// MAIN
int main()
{
  Mortgage m;
  double tmpl, tmpr;
  int tmpy;
  do
  {
      cout << "Enter the loan amount in dollars: ";
      cin >> tmpl;
      if(tmpl < 0)
	cout << "ERROR: Loan cannot be less than zero." << endl;
  }
  while(tmpl < 0);

  cout << "Enter the annual interest rate in decimal form: ";
  cin >> tmpr;

  cout << "Enter the length of the loan in years: ";
  cin >> tmpy;

  m.set(tmpl, tmpr, tmpy);

  m.print();
  cout << "Monthly Payment: $" << fixed << showpoint << setprecision(2) << m.calcMonthly() << endl;
  return 0;
}
