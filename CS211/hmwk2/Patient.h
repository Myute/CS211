/* Class: Patient.h
 * Project: Homework 2
 * Author: Kevyn Higbee
 * Date Due: March 6, 2018
 */
#ifndef PATIENT_H
#define PATIENT_H

#include <vector>
#include <string>
#include "Checkup.h"

using namespace std;

class Patient
{
 private:
  static long nextPatientAccountNum;
  const long patientAccountNum;

  string firstName, lastName, birthDate;
  long ssn;
  char gender;
  vector<Checkup> patientCheckups;

 public:
  // constructors
  Patient();
  Patient(string, string, string, long, char);
  // setter functions
  void setFirst(string);
  void setLast(string);
  void setBirthDate(string);
  void setSSN(long);
  void setGender(char);
  // getter functions
  string getFirst() const;
  string getLast() const;
  string getBirthDate() const;
  long getPatientAccountNum() const;
  long getSSN() const;
  char getGender() const;
  vector<Checkup>& getCheckups();
  // other functions
  void addCheckup(string, double, double, int, int, int, int, string); 
  // operator overload cuz stuff isnt working
  Patient operator=(const Patient&);
};
#endif
