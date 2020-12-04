#include <iostream>
#include "Course.h"

void Course::setCourse(long cNum, string cName, int numCred)
{
  courseNumber = cNum;
  courseName = cName;
  numberOfCredits = numCred;
}

void Course::print()
{
  cout << courseNumber << " " << courseName << " " << numberOfCredits << " ";
}
