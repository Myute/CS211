#include "Image.h"

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