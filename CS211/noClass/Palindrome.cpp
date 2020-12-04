#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(const string& s, int i);

int main()
{
  string str;
  cout << "Enter a word or Phrase to check if it's a palindrome: " << endl;
  getline(cin, str);
  cout << endl;

  if(isPalindrome(str, 0))
    cout << "This is a Palindrome" << endl;
  else
    cout << "This is not a Palindrome" << endl;
 
  return 0;
}

bool isPalindrome(const string& s, int i)
{
  if(i > s.length()/2)
    return true;
  else
    if(s[i] == s[s.length() - i - 1])
      return isPalindrome(s, i+1);
    else
      return false;
}
