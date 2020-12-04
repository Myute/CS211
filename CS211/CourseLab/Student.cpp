#include "Student.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int Student::totalNumofStudents = 0;
int Student::nextStudentID = 10000;

Student::~Student()
{
  totalNumofStudents--;
}
Student::Student():studentID(Student::nextStudentID)
{
  name = "Unknown";
  major = "CS";
  classification = "Undergraduate";
  units = 12;
  tuition = 0;

  totalNumofStudents++;
  nextStudentID++;
};
Student::Student(string theName, string theMajor, string theClassification, int theUnits):studentID(Student::nextStudentID)
{
  name = theName;
  major = theMajor;
  classification = theClassification;
  units = theUnits;
  tuition = 0;
  
  totalNumofStudents++;
  nextStudentID++;
};
void Student::print() const
{
  cout << "Name: " << name << endl
       << "Major: " << major << endl
       << "Classification: " << classification << endl
       << "Units: " << units << endl
       << "Student ID: " << studentID << endl
       << "Tuition: $" << fixed << showpoint << setprecision(2) << tuition << endl
       << "Total Number of Student: " << totalNumofStudents << endl
       << endl;
}
void Student::getData()
{
  cout << "Enter the student's name: ";
  getline(cin, name);
  cout << "Enter the student's major: ";
  cin >> major;
  cout << "Enter the student's classification: ";
  cin >> classification;
  cout << "Enter the number of units the student is taking: ";
  cin >> units;
  cout << endl;
}
