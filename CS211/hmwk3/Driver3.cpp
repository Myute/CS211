/**
 * Assignment: Homework 3, Problem 3
 * Class: Driver3.cpp
 * Author: Kevyn Higbee
 * Date Due: April 10, 2018
 */

#include "Patient.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
  Patient *list[4];
  // create new patient objects in heap
  list[0] = new Patient(10023, "Joe Garcia", 'M', "11/10/1979");
  list[1] = new Patient(10024, "Suzy Walter", 'F', "01/01/2010");
  list[2] = new Patient(10025, "Amelia Perez", 'F', "12/05/1983");
  list[3] = new Patient(10026, "Tim Ducrest", 'M', "01/12/2000");

  // print header
  cout << left << setw(9) << "ID" << setw(15) << "Name" << setw(15) << "Birth Date" << "Gender" << endl
       << "------------------------------------------------" << endl;
  // print each patient
  for(int i = 0; i < 4; i++)
    cout << list[i] -> toString() << endl;

  // free list back to heap
  for(int i = 0; i < 4; i++)
    delete list[i];
  
  return 0;
}
