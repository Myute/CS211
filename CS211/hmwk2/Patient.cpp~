/* Class: Patient.cpp
 * Project: Homework 2
 * Author: Kevyn Higbee
 * Date Due: March 6, 2018
 */
#include "Patient.h"

using namespace std;

// initialize static values
long Patient::nextPatientAccountNum = 5000;

// constructor definitions
Patient::Patient():patientAccountNum(Patient::nextPatientAccountNum)
{
  firstName = "First";
  lastName = "Last";
  birthDate = "Date";
  ssn = 0;
  gender = 'm';
  
  nextPatientAccountNum += 2;
};
Patient::Patient(string first, string last, string birth, long social, char g):patientAccountNum(Patient::nextPatientAccountNum)
{
  firstName = first;
  lastName = last;
  birthDate = birth;
  ssn = social;
  gender = g;
  
  nextPatientAccountNum += 2;
};

// setter functions
void Patient::setFirst(string first) { firstName = first; };
void Patient::setLast(string last) { lastName = last; };
void Patient::setBirthDate(string birth) { birthDate = birth; };
void Patient::setSSN(long social) { ssn = social; };
void Patient::setGender(char g) { gender = g; };

// getter functions
string Patient::getFirst() const { return firstName; };
string Patient::getLast() const { return lastName; };
string Patient::getBirthDate() const { return birthDate; };
long Patient::getPatientAccountNum() const { return patientAccountNum; };
long Patient::getSSN() const { return ssn; };
char Patient::getGender() const { return gender; };
vector<Checkup>& Patient::getCheckups() { return patientCheckups; };

// other functions
void Patient::addCheckup(string cDate, double pHeight, double pWeight, int pChol, int pHDL, int pTrig, int pGlu, string bPress) 
{
  Checkup c(cDate, bPress, pHeight, pWeight, pChol, pHDL, pTrig, pGlu);
  patientCheckups.push_back(c); 
};
Patient Patient::operator=(const Patient& p)
{
  Patient tmp(p.getFirst(), p.getLast(), p.getBirthDate(), p.getSSN(), p.getGender());
  return tmp;
};
