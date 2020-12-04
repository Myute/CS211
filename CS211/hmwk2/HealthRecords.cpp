/* Class: HealthRecords.cpp
 * Project: Homework 2
 * Author: Kevyn Higbee
 * Date Due: March 6, 2018
 */

#include "HealthRecords.h"
#include "Patient.h"
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;

// constructors
HealthRecords::HealthRecords() { /* Empty Constructor */ };
// gettter functions
vector<Patient>& HealthRecords::getPatients() { return patientRecords; };

// other functions

// adds a new patient to the array
void HealthRecords::createNewPatient(string first, string last, long social, char g, string birth)
{
  bool found = false;
  
  for(int z = 0; z < patientRecords.size(); z++)
    if(social == patientRecords[z].getSSN())
      found = true;

  if(found == false)
    {
      Patient p(first, last, birth, social, g);
      patientRecords.push_back(p);
    }
  else
    cout << "Cannot add patient. SSN Already exists\n";
};

// prints all patients in the system, if any
void HealthRecords::printAllPatients()
{
  cout << "All Patient Records:" << endl
       <<   "-----------------------------------------------" << endl;
  
  if(patientRecords.empty())
    cout << "No Patients in System.\n"
	 << "-----------------------------------------------" << endl;
  else
    for(int i = 0; i < patientRecords.size(); i++) // prints a patients basic info
	cout << "Account Number: " << patientRecords[i].getPatientAccountNum() 
	     << "\nName: " << patientRecords[i].getFirst() << " " << patientRecords[i].getLast()
	     << "\nGender: " << patientRecords[i].getGender()
	     << "\nDate of Birth: " << patientRecords[i].getBirthDate() << endl
	     << "-----------------------------------------------" << endl;
};

// prints the checkup vector in a patient 
void HealthRecords::printPatientCheckupSummary(long pNum, string sDate)
{
  bool foundDate = false;
  int pIndex = -1, pDate = -1, currYear = 2018, birthYear, count = 0;
  stringstream date, notes, height;
  double intpart, fractpart;
  string gender;
  // find index of person
  for(int i = 0; i < patientRecords.size(); i++)
    if(patientRecords[i].getPatientAccountNum() == pNum)
      {
	pIndex = i;
	i = patientRecords.size();
      }
  // if the patient number is not in list
  if(pIndex == -1)
    cout << "No patient with " << pNum << "." << endl << "\nAge " << (currYear - birthYear);
  else
    { // find the corresponding date index on checkups
      for(int x = 0; x < patientRecords[pIndex].getCheckups().size(); x++)
	{
	if(patientRecords[pIndex].getCheckups()[x].getDate() == sDate)
	  {
	    pDate = x;
	    x = patientRecords[pIndex].getCheckups().size();
	  }
	}
      if(pDate == -1)
	cout << "Patient does not have Checkups with this date.\n";
      else
	{ // cuz i wanna print Female/Male instead of f/m
	  if(patientRecords[pIndex].getGender() == 'M')
	    gender = "Male";
	  else
	    gender = "Female";

	  date << patientRecords[pIndex].getBirthDate().substr(6,4);// getting the birthyear as an int so we can
	  date >> birthYear;                                        // calculate the age
	  
	  fractpart = modf(patientRecords[pIndex].getCheckups()[pDate].getHeight(), &intpart);
	  fractpart = (fractpart*10);
	  height << intpart << "'" << fractpart << "\""; // so height can be printed the same way as the example
	  // really big output statement for patient output
	  cout <<  "Name: " << patientRecords[pIndex].getFirst() << " " << patientRecords[pIndex].getLast()
	       << "\nBorn on: " << patientRecords[pIndex].getBirthDate() << ", " << gender << endl 
	       << (currYear - birthYear) << " years old, " << height.str() << ", " << patientRecords[pIndex].getCheckups()[pDate].getWeight() << " pounds\n"
	       << "                                     " << sDate << endl
	       << "--------------------------------------------" << endl
	       << left << setw(39) << "Total Cholesterol: " << patientRecords[pIndex].getCheckups()[pDate].getCholesterol()
	       << "\n(Reference Range: 125-199mg/dL)\n"
	       << setw(40) << "\nHDL Cholesterol: " << patientRecords[pIndex].getCheckups()[pDate].getHDLCholesterol()
	       << "\n(Reference Range: > or = 40 mg/dL)\n"
	       << setw(40) << "\nTriglycerides: " << patientRecords[pIndex].getCheckups()[pDate].getTriglycerides()
	       << "\n(Reference Range: < 150 mg/dL)\n"
	       << setw(40) <<"\nLDL Cholesterol: " <<  patientRecords[pIndex].getCheckups()[pDate].calcLDL()
	       << "\n(Reference Range: < 130 mg/dL)\n"
	       << setw(40) << "\nCholesterol/HDL Ratio: " << patientRecords[pIndex].getCheckups()[pDate].calcCholRatio()
	       << "\n(Reference Range: < or = 5.0)\n"
	       << setw(40) << "\nGlucose: " << patientRecords[pIndex].getCheckups()[pDate].getGlucose()
	       << "\n(Reference Range: 65-99 mg/dL)\n"
	       << setw(40) << "\nBlood Pressure: " << patientRecords[pIndex].getCheckups()[pDate].getBloodPressure()
	       << "\n(Reference Range: < 120/80 mmHg)\n"
	       << setw(40) << "\nBody Mass Index: " << fixed << showpoint << setprecision(2) << patientRecords[pIndex].getCheckups()[pDate].calcBodyMassIndex()
	       << "\n(Reference Range: 18.5-24.9)\n"
	       << "--------------------------------------------"
	       << "\nNotes to patient:\n";

	  if((patientRecords[pIndex].getCheckups()[pDate].getCholesterol()) > 199 || (patientRecords[pIndex].getCheckups()[pDate].getCholesterol() < 125)
	     || (patientRecords[pIndex].getCheckups()[pDate].getHDLCholesterol() < 40) || (patientRecords[pIndex].getCheckups()[pDate].getTriglycerides() >= 150)
	     || (patientRecords[pIndex].getCheckups()[pDate].calcLDL() > 130) || (patientRecords[pIndex].getCheckups()[pDate].calcCholRatio() > 5)
	     || (patientRecords[pIndex].getCheckups()[pDate].getGlucose() < 65) || (patientRecords[pIndex].getCheckups()[pDate].getGlucose() > 99))
	    {
	      notes << " - Has a high risk of cornonary heart disease.\n";
	      count++; // so we know not to print the no note message
	    }
	  
	  if((patientRecords[pIndex].getCheckups()[pDate].getBloodPressureTopVal() > 120) || (patientRecords[pIndex].getCheckups()[pDate].getBloodPressureBottomVal() > 80))
	    {
	      notes << " - May have \"hypertension\" due to blood pressure.\n";
	      count++;
	    }

	  if(patientRecords[pIndex].getCheckups()[pDate].calcBodyMassIndex() < 18.5)
	    {
	      notes << " - Is Underweight with increased risk of electrolyte imbalances and osteoporosis.\n";
	      count++;
	    }
	  else 
	    if(patientRecords[pIndex].getCheckups()[pDate].calcBodyMassIndex() > 24.9)
	      {
		notes << " - Is Overweight with increased risk for health conditions such as heart disease, stroke.\n";
		count++;
	      }
	  
	  if(count == 0)
	    cout << "Nothing...\n";
          else
	    cout << notes.str();
	    cout << "--------------------------------------------" << endl;
	}
    }
};


// prints all the history of a patient
void HealthRecords::printPatientHistory(long pNum)
{
  int pIndex = -1;
  for(int i = 0; i < patientRecords.size(); i++) // find patient with same account num
    if(patientRecords[i].getPatientAccountNum() == pNum)
      {
	pIndex = i;
	i = patientRecords.size();
      }
  // output patient stuff
  cout << patientRecords[pIndex].getFirst() << " " << patientRecords[pIndex].getLast()
       << "\nBorn on " << patientRecords[pIndex].getBirthDate() << endl
       << right << setw(50);
  // output more patient stuff
  for(int z = 0; z < patientRecords[pIndex].getCheckups().size(); z++)
    cout << patientRecords[pIndex].getCheckups()[z].getDate() << "  "; 
  // output even more patient stuff and soome formatting stuff
  cout << "\n------------------------------------------------------------------------------------------------" << endl
       << left << setw(42) << "Total Cholesterol: ";
  for(int z = 0; z < patientRecords[pIndex].getCheckups().size(); z++)
    cout << left << setw(12) << patientRecords[pIndex].getCheckups()[z].calcTotalCholesterol();
  
  cout << "\n(Reference Range: 125-199mg/dL)\n"
       << left << setw(43) << "\nHDL Cholesterol: ";

  for(int z = 0; z < patientRecords[pIndex].getCheckups().size(); z++)
    cout << left << setw(12) << patientRecords[pIndex].getCheckups()[z].getHDLCholesterol();

  cout << "\n(Reference Range: > or = 40 mg/dL)\n"
       << left << setw(43) << "\nTriglycerides: ";
  
  for(int z = 0; z < patientRecords[pIndex].getCheckups().size(); z++)
    cout << left << setw(12) << patientRecords[pIndex].getCheckups()[z].getTriglycerides();
  
  cout << "\n(Reference Range: < 150 mg/dL)\n"
       << left << setw(43) << "\nLDL Cholesterol: ";

  for(int z = 0; z < patientRecords[pIndex].getCheckups().size(); z++)
    cout << left << setw(12) << patientRecords[pIndex].getCheckups()[z].calcLDL();

  cout << "\n(Reference Range: < 130 mg/dL)\n"
       << left << setw(43) << "\nCholesterol / HDL Cholesterol Ratio: ";

  for(int z = 0; z < patientRecords[pIndex].getCheckups().size(); z++)
    cout << left << setw(12) << patientRecords[pIndex].getCheckups()[z].calcCholRatio();

  cout << "\n(Reference Range: < or = 5.0)\n"
       << left << setw(43) << "\nGlucose: ";

  for(int z = 0; z < patientRecords[pIndex].getCheckups().size(); z++)
    cout << left << setw(12) << patientRecords[pIndex].getCheckups()[z].getGlucose();

  cout << "\n(Reference Range: 65-99 mg/dL)\n" << endl
       << left << setw(42) << "Blood Pressure: ";

  for(int z = 0; z < patientRecords[pIndex].getCheckups().size(); z++)
    cout << left << setw(12) << patientRecords[pIndex].getCheckups()[z].getBloodPressure();

  cout << "\n(Reference Range: < 120/80 mmHg)\n"
       << left << setw(43) << "\nBody Mass Index: ";

  for(int z = 0; z < patientRecords[pIndex].getCheckups().size(); z++)
    cout << left << setw(12) << patientRecords[pIndex].getCheckups()[z].calcBodyMassIndex();

  cout << "\n(Reference Range: 18.5-24.9)" << endl 
       << "\n------------------------------------------------------------------------------------------------\n"; 

};

// processes a trasnaction file
void HealthRecords::processTransactionFile(string fileName)
{
  fstream fin;
  string command, fName, lName, pBirth, cDate, pBloodPressure;
  long pSSN, pNum;
  char pG;
  int pIndex = -1, pCholesterol, pHDL, pTriglyceride, pGlucose;
  double pHeight, pWeight;
 
  fin.open(fileName.c_str());
  if(!fin)
    cout << "\nUnable to open file. . . \n";
  else
    while(fin >> command)
      {// this giant equals line is so i could tell where each iteration of the loop started
	cout << "===============================================================================================" << endl;
	if(command == "CreateNewPatient")
	  {// each if statement is for a command
	    fin >> fName >> lName >> pSSN >> pG >> pBirth;
	    cout << command << " " << fName << " " << lName << " " << pSSN << " " << pG << " " << pBirth << endl << endl;
	    createNewPatient(fName, lName, pSSN, pG, pBirth);
	  }
	else
	  if(command == "PrintAllPatients")
	    {
	      cout << command << endl << endl;
	      printAllPatients();
	    }
	  else
	    if(command == "AddPatientCheckup")
	      {
		fin >> pNum >> cDate >> pHeight >> pWeight >> pCholesterol >> pHDL >> pTriglyceride >> pGlucose >> pBloodPressure;

		cout << command << " " << pNum << " " << cDate << " " << pHeight << " " << pWeight << " "
		     << pCholesterol << " " << pHDL << " " << pTriglyceride << " " << pGlucose << " " << pBloodPressure << endl << endl;

		for(int z = 0; z < patientRecords.size(); z++)
		  if(patientRecords[z].getPatientAccountNum() == pNum)
		    {
		      pIndex = z;
		      z = patientRecords.size();
		    }
		if(pIndex == -1)
		  cout << "No Patient with Account Number " << pNum << endl;
		else
		  patientRecords[pIndex].addCheckup(cDate, pHeight, pWeight, pCholesterol, pHDL, pTriglyceride, pGlucose, pBloodPressure);
	      }
		  else
		    if(command == "PrintPatientHistory")
		      {
			fin >> pNum;
			cout << command << " " << pNum << endl << endl;
			for(int x = 0; x < patientRecords.size(); x++)
			  if(patientRecords[x].getPatientAccountNum() == pNum)
			    {
			      pIndex = x;
			      x = patientRecords.size();
			    }
			if(pIndex == -1)
			  cout << "No Patient with Account Number " << pNum << endl;
			else
			  printPatientHistory(pNum);
		      }
		    else
		      if(command == "PrintPatientCheckupSummary")
			{
			  fin >> pNum >> cDate;
			  cout << command << " " << pNum << " " << cDate << endl << endl;

			  for(int y = 0; y < patientRecords.size(); y++)
			    if(patientRecords[y].getPatientAccountNum() == pNum)
			      {
				pIndex = y;
				y = patientRecords.size();
			      }
			  if(pIndex == -1)
			    cout << "No Patient with Account Number " << pNum << endl;
			  else
			    {
			      printPatientCheckupSummary(pNum, cDate);
			    }
			}
		      else
			if(command == "PrintPatientHistory")
			  {
			    fin >> pNum;
			    cout << command << pNum << endl << endl;
			    printPatientHistory(pNum);
			  }
	pIndex = -1; // reset the index so that we dont accidentaly reuse it
      }
};
