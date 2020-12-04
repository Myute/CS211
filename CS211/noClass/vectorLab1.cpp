#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

void del(vector<string>&,int);
void insert(vector<string>&, string, int);
void print(const vector<string>&);

int main()
{
  ifstream inFile;
  vector<string> v(1);
  
  string tmp;
  int index;

  inFile.open("vectorData.txt");

  do
    {
      inFile >> tmp;

      if(tmp == "Delete")
	{
	  inFile >> index;
	  del(v, index);
	}
      else
	if(tmp == "Insert")
	  {
	    inFile >> tmp >> index;
	    insert(v, tmp, index);
	  }
	else
	  if(tmp == "Print")
	    print(v);
    }
  while(inFile);
  return 0;
}

void del(vector<string>& v, int index)
{
  if(index > -1 && index < v.size()-1)
    v.erase(v.begin()+index);
  else
    cout << "error del at " << index << endl;
}
void insert(vector<string>& v, string str, int index)
{
  //cout << str << endl;
  
  if(index > -1 && index < v.size())
    v.insert(v.begin()+index, str);
  else
    cout << "error add at " << index << endl;
}
void print(const vector<string>& v)
{
  for(int i = 0; i < v.size(); i++)
    cout << v[i] << " ";
  cout << endl;
}
