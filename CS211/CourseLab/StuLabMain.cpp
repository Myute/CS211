#include <iostream>
#include <string>
#include "Student.h"

using namespace std;

int main()
{
  Student student1;
  student1.print();

  Student student2("Unknown", "PHYS", "graduate", 0);
  student2.getData();
  student2.print();

  return 0;
}
