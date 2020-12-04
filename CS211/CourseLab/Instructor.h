#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include "Course.h"

using namespace std;

class Instructor
{
 private:
  string firstName;
  string lastName;
  char gender;
  long employeeID;
  string officeNum;
  Course courses[3];
 
 public:
  void set(string fName, string lName, char g, long ID, string offNum, long cN0,  string cName0, int num0, long cN1, string cName1, int num1, long cN2, string cName2, int num2);
  void print();
};

#endif
