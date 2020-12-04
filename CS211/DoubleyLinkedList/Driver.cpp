
#include <iostream>
#include <string>
#include "Image.h"
#include "ImageViewer.h"

using namespace std;

int main ()
{
  ImageViewer list1;

  list1.addImage ("C:/Users/Mayssaa/CS211/HW4/roadtrip", 3840, "jpg", "3376x6000");
  list1.addImage ("C:/Users/Mayssaa/CS211/HW4/graduation", 4370, "jpg","6000×3376");
  list1.addImage ("C:/Users/Mayssaa/CS211/HW4/family", 3330, "jpg","2400×4240");
  list1.addImage ("C:/Users/Mayssaa/CS211/HW4/party", 373, "jpg", "960×1280");
  list1.addImage ("C:/Users/Mayssaa/CS211/HW4/car", 1770, "jpg", "2448×3264");
  list1.addImage ("C:/Users/Mayssaa/CS211/HW4/beach", 302, "jpg", "2048×1365");
  list1.addImage ("C:/Users/Mayssaa/CS211/HW4/mountains", 243, "png", "1280×798");
  list1.addImage ("C:/Users/Mayssaa/CS211/HW4/baby", 960, "png", "1024×746");

  cout << endl;
  list1.print();
  cout << endl;

  return 0;
}
