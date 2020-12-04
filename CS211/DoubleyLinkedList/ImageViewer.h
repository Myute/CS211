#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include"Image.h"
#include<string>

using namespace std;

class ImageViewer
{
 private:
  Image* head;
 public:
  ImageViewer();
  ~ImageViewer();
  void addImage(string n, double s, string f, string r);
  void print();
};

#endif
