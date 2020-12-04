/* Class: Checkup.h
 * Project: Homework 2
 * Author: Kevyn Higbee
 * Date Due: March 6, 2018
 */
#ifndef CHECKUP_H
#define CHECKUP_H

#include <string>

using namespace std;

class HealthRecord;
class Patient;

class Checkup
{ 
 private: 
  string checkUpDate, bloodPressure;
  double height, weight;
  int cholesterol, hdlCholesterol, triglycerides, glucose;

 public:
  // class constructors
  Checkup();
  Checkup(string, string, double, double, int, int, int, int);
  // getter functions
  string getDate();
  string getBloodPressure();
  double getHeight();
  double getWeight();
  int getCholesterol();
  int getHDLCholesterol();
  int getTriglycerides();
  int getGlucose();
  // setter functions
  void setDate(string);
  void setBloodPressure(string);
  void setHeight(double);
  void setWeight(double);
  void setCholesterol(int);
  void setHDLCholesterol(int);
  void setTriglycerides(int);
  void setGlucose(int);
  // other functions
  double calcLDL();
  double calcCholRatio();
  double calcBodyMassIndex();
  double calcTotalCholesterol();
  int getBloodPressureTopVal();
  int getBloodPressureBottomVal();
};
#endif
