/**
 * Assignment: Homework 3, Problem 3
 * Class: Patient.cpp
 * Author: Kevyn Higbee
 * Date Due: April 10, 2018
 */

#include "Patient.h"
#include <sstream>
#include <iomanip>

Patient::Patient(long id, string n, char g, string birth)
{
  patientID = id;
  name = n;
  gender = g;
  birthDate = birth;
};

string Patient::toString()
{
  stringstream str;

  str << left << setw(9) << patientID << setw(15) << name << setw(15) << birthDate << gender;
  
  return str.str();
};
