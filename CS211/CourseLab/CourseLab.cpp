#include "Instructor.h"

using namespace std;

int main()
{
  Instructor inst;
 
  inst.set("Michelle", "James", 'F', 2390878, "SBSB3024", 24540, "CS111", 3, 24541, "CS111", 1, 22275, "CS351", 3);

  inst.print();

  return 0;
}
