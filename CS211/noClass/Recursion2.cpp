#include <iostream>
#include <string>

using namespace std;

int numChars(string, char, int);

int main()
{
  string str;
  char find;

  cout << "Enter a string: ";
  getline(cin, str);
  cout << "Enter a character: ";
  cin >> find;

  cout << "'" << find << "' occurs " << numChars(str, find, str.length()) << " times.\n";
  return 0;
}

int numChars(string str, char c, int i)
{
  if(i == 0)
    if(str[i] == c)
      return 1;
    else
      return 0;
  else
    if(str[i] == c)
      return 1 + numChars(str, c, i -1);
    else
      return 0 + numChars(str, c, i -1);
}
