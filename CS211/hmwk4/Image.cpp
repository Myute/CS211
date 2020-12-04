/*******************************************
 *  Class - Image.cpp
 *  Assignment - A4
 *  Author - Kevyn Higbee
 *  Date - 4/23/2018
 ******************************************/

#include "Image.h"
#include <iostream>

using namespace std;

Image::Image(string n, double s, string f, string r)
{
  name = n;
  size = s;
  format = f;
  resolution = r;

  prev = NULL;
  next = NULL;
}
void Image::print()
{
  cout << name << " " 
       << size << " " 
       << format << " " 
       << resolution << endl;
}
