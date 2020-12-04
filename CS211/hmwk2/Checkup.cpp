/* Class: HealthRecords.cpp
 * Project: Homework 2
 * Author: Kevyn Higbee
 * Date Due: March 6, 2018
 */
#include "Checkup.h"
#include <sstream>

using namespace std;


// Constructor Definitions
Checkup::Checkup() // Default Constructor
{
  checkUpDate = "Invalid Date";
  bloodPressure = "0 / 0";
  height = 0;
  weight = 0;
  cholesterol = 0;
  hdlCholesterol = 0;
  triglycerides = 0;
  glucose = 0;
};
Checkup::Checkup(string date, string bPressure, double h, double w, int chol, int HDLChol, int trig, int glu) // Parameter Constructor
{
  checkUpDate = date;
  bloodPressure = bPressure;
  height = h;
  weight = w;
  cholesterol = chol;
  hdlCholesterol = HDLChol;
  triglycerides = trig;
  glucose = glu;
};

// getter methods
string Checkup::getDate() { return checkUpDate; };
string Checkup::getBloodPressure() { return bloodPressure; };
double Checkup::getHeight() { return height; };
double Checkup::getWeight() { return weight; };
int Checkup::getCholesterol() { return cholesterol; };
int Checkup::getHDLCholesterol() { return hdlCholesterol; };
int Checkup::getTriglycerides() { return triglycerides; };
int Checkup::getGlucose() { return glucose; };

// setter functions
void Checkup::setDate(string date) { checkUpDate = date; };
void Checkup::setBloodPressure(string bPressure) { bloodPressure = bPressure; };
void Checkup::setHeight(double h) { height = h; };
void Checkup::setWeight(double w) { weight = w; };
void Checkup::setCholesterol(int chol) { cholesterol = chol; };
void Checkup::setHDLCholesterol(int hdl) { hdlCholesterol = hdl; };
void Checkup::setTriglycerides(int trig) { triglycerides = trig; };
void Checkup::setGlucose(int glu) { glucose = glu; };

// other functions
double Checkup::calcLDL() { return (cholesterol - (hdlCholesterol + triglycerides/5)); };
double Checkup::calcCholRatio() { return cholesterol / hdlCholesterol; };
double Checkup::calcBodyMassIndex() { return (weight*703)/((height*12)*(height*12)); };
double Checkup::calcTotalCholesterol() { return cholesterol + hdlCholesterol; };

int Checkup::getBloodPressureTopVal() 
{
  stringstream str;
  int tmp = 0;
  str << bloodPressure.substr(0,bloodPressure.find("/"));
  str >> tmp;
  return tmp;
};
int Checkup::getBloodPressureBottomVal() 
{ 
  stringstream str;
  int tmp = 0;
  str << bloodPressure.substr(bloodPressure.find("/"), bloodPressure.length());
  str >> tmp;
  return tmp;
};
