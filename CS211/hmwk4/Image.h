/*******************************************
 *  Class - Image.h
 *  Assignment - A4
 *  Author - Kevyn Higbee
 *  Date - 4/23/2018
 ******************************************/
#ifndef IMAGE_H
#define IMAGE_H

#include<string>

using namespace std;

class ImageViewer;

class Image
{
  friend ImageViewer;
 private:
  string name;
  double size;
  string format;
  string resolution;
  Image* next;
  Image* prev;
 public:
  Image(string n, double s, string f, string r);
  void print();
};

#endif
