#include <iostream>
#include <string>

using namespace std;

void replaceSubstring(string&, string, string);

int main()
{
  string str1, str2, str3;

  // get user input
  cout << "String 1: ";
  getline(cin, str1);
  cout << "String 2: ";
  getline(cin, str2);
  cout << "String 3: ";
  getline(cin, str3);

  replaceSubstring(str1,str2,str3);
  cout << "\n\n" << str1 << "\n";

  return 0;
}

void replaceSubstring(string& str1, string str2, string str3)
{
  int p;
  // search for occurence
  p = str1.find(str2, 0);
  while(p != str1.npos)
    {
      str1.replace(p,3,str3);
      p = str1.find(str2, p);
    }
}
