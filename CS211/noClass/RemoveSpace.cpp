#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string removeSpace(string str);

int main()
{
  string string1;
  cout << "Please enter a phrase: ";
  getline(cin, string1);
  cout << "The resulting phrase is: " << removeSpace(string1) << endl;
  
  return 0;
}

string removeSpace(string string1)
{
  string word, final;
  stringstream stream1;
  stream1.str(string1);

  while(stream1 >> word)
    final+=word;
  
  return final;
}
