#include <iostream>
#include <string>

using namespace std;

void reverse(const string&, int);

int main()
{
  string str;
  // get user input
  cout << "Enter a word or phrase: " << endl;
  getline(cin, str);
  cout << endl;

  reverse(str, 0);

  cout << endl;
  return 0;
}

void reverse(const string& s, int i)
{
  if(s.length() == i)
    cout << s[i];
  else
    {
      reverse(s, i + 1);
      cout << s[i];
    }
}
