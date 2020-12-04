/* Class: HealthRecords.h
 * Project: Homework 2
 * Author: Kevyn Higbee
 * Date Due: March 6, 2018
 */
#ifndef HEALTHRECORDS_H
#define HEALTHRECORDS_H

#include <fstream>
#include <iomanip>
#include <vector>
#include <iostream>
#include <string>
#include "Patient.h"

using namespace std;

class HealthRecords
{
 private:
  vector<Patient> patientRecords;

 public:
  // constructor
  HealthRecords();
  // getter functions
  vector<Patient>& getPatients();
  // other functions
  void createNewPatient(string, string, long, char, string);
  void printAllPatients();
  void addPatientCheckup(long, string, double, double, double, double, double, double, double);
  void printPatientCheckupSummary(long, string);
  void printPatientHistory(long);
  void processTransactionFile(string);
  
};
#endif
