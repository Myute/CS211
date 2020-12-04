/**
 * Assignment: Homework 3, Problem 1
 * Class: Patient.h
 * Author: Kevyn Higbee
 * Date Due: April 10, 2018
 */

#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include <sstream>

using namespace std;

class Patient
{
 private:
  long patientID;
  string name;
  char gender;
  string birthDate;
 public:
  Patient(long, string, char, string);
  string toString();
};
#endif
