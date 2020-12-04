#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

struct Employee
{
  string name;
  long SSN;
  float grossIncome;
  float taxes;
};

void read(vector<Employee>&);
float calcNet(Employee);
void print(const vector<Employee>&);

int main()
{
  vector<Employee> list;
  read(list);
  print(list);
  return 0;
}
void read(vector<Employee>& list)
{
  Employee  emp;
  ifstream fin;
  fin.open("employeeData.txt");
  while(fin)
    {
      fin >> emp.name >> emp.SSN >> emp.grossIncome >> emp.taxes;
      list.push_back(emp);
    }
  list.pop_back();
}
void print(const vector<Employee>& list)
{
  cout << left << setw(10) << "Name" << setw(13) << "SSN" << setw(16) << "GrossIncome" << setw(7) << "Taxes" << setw(10) << "NetIncome" << endl <<
    "---------------------------------------------------------" << endl;
  for(int i = 0; i < list.size(); i++)
    cout << left << setw(10) << list[i].name 
	 << setw(12) << list[i].SSN 
	 << right << fixed << showpoint << setprecision(2) << setw(12) << list[i].grossIncome 
	 << setw(10) << list[i].taxes * list[i].grossIncome
	 << setw(10) << calcNet(list[i]) << endl;
}
float calcNet(Employee emp)
{
  float netIncome;

  netIncome = emp.grossIncome - (emp.grossIncome * emp.taxes);

  return netIncome;
}
