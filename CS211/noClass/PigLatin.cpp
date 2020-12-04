#include <iostream>
#include <string>

using namespace std;

void modify(string&);

int main()
{
  string phrase;
  cout << "English: ";
  getline(cin, phrase);

  modify(phrase);

  cout << "Pig Latin: " << phrase << endl;
  return 0;
}
void modify(string& phrase)
{
  string tmp;
  string tmp2;
  int beg = 0, end;
  
  end = phrase.find(" ", beg);
  
  while(end != phrase.npos)
    {
      tmp = phrase.substr(beg,end - beg);
      tmp.append(tmp.substr(0,1));
      tmp.erase(0,1);
      tmp.append("ay ");
      tmp2.append(tmp);
      phrase.erase(beg, end+1);
      end = phrase.find(" ", beg);
    }

  tmp = phrase;
  tmp.append(tmp.substr(0,1));
  tmp.erase(0,1);
  tmp.append("ay");
  tmp2.append(tmp);
  phrase = tmp2;
}
