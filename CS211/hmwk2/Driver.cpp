/* Class: Driver.cpp
 * Project: Homework 2
 * Author: Kevyn Higbee
 * Date Due: March 6, 2018
 */
#include "HealthRecords.h"

using namespace std;

int main()
{
  HealthRecords hr; // create object then process file
  hr.processTransactionFile("HW2.txt");

  return 0;
};
