#include "ImageViewer.h"
#include <string>
#include <iostream>

using namespace std;

ImageViewer::ImageViewer()
{
  head = NULL;
}
ImageViewer::~ImageViewer()
{
  Image *imgPtr = head;
  Image *currentPtr = NULL;
  while(imgPtr)
    {
      currentPtr = imgPtr;
      imgPtr = imgPtr -> next;
      delete currentPtr;
    }
}
void ImageViewer::addImage(string n, double s, string f, string r)
{
  Image* imgPtr = new Image(n,s,f,r);
  Image* current = head;
  // if list is empty
  if(!head)
    head = imgPtr;
  else
    if(head -> name >= imgPtr -> name) // if new image needs to be inserted at head of list
      {
	imgPtr -> next = head;
	head -> prev = imgPtr;
	head = imgPtr;
      }
    else
      {
	while(current -> next && current -> next -> name < imgPtr -> name) // traverse list until place is found or at end of list
	  current = current -> next;
	imgPtr -> next = current -> next;

	if(current -> next) // if reached end of list
	  imgPtr -> next -> prev = imgPtr;
	
	current -> next = imgPtr; 
	imgPtr -> prev = current;
      }
}
void ImageViewer::print()
{
  Image *imgPtr = head;
  while(imgPtr)
    {
      cout << imgPtr -> name << " " << imgPtr -> size << " " << imgPtr -> format << " " << imgPtr -> resolution << endl;
      imgPtr = imgPtr -> next;
    }
}
