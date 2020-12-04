#include <iostream>
#include <vector>
#include <string>

using namespace std;

void sort(vector<string>&);
void display(const vector<string>&);
int binSearch(const vector<string>&, string key);

int main()
{
  vector<string> v {"Joe Garcia", "Amelia Perez", "Bob Haynes", "Tim Ducrest", "Kevin Garcia", "Suzy Walter", "Fang Yi", "Robert James", "Mary Andres"};
  int index;
  
  display(v);
  sort(v);
  display(v);
  
  // search and display search
  cout << "Searching For \"Kevin Garcia\"..." << endl;
  index = binSearch(v, "Kevin Garcia");
  if(index != -1)
    cout << v[index] << " in index " << index << endl;
  else
    cout << "Could not find name in list..." << endl << endl;
  
  // search and display search
  cout << "Searching for \"Joe James\"..." << endl;
  index = binSearch(v, "Joe James");
  if(index != -1)
    cout << v[index] << " in index " << index << endl;
  else
    cout << "Could not find name in list..." << endl;
  
  return 0;
}

void sort(vector<string>& v)
{
  int min = 0;
  string tmp = "";
  
  for(int outer = 0; outer < v.size() - 1; outer++)
    {
      min = outer;

      for(int inner = outer + 1; inner < v.size(); inner++)
	  if(v[inner] < v[min])
	    min = inner;

      tmp = v[outer];
      v[outer] = v[min];
      v[min] = tmp;
    }
}
void display(const vector<string>& v)
{
  cout << "Printing List" << endl
       << "--------------------" << endl;

  for(int i = 0; i < v.size(); i++)
    cout << v[i] << endl;
  cout << endl;
}
int binSearch(const vector<string>& v, string key)
{
  int upper = v.size(), lower = 0;
  int search;
  while(lower <= upper)
    {
      search = (upper + lower)/2;
      if(v[search] == key)
	return search;
      else if(v[search] < key)
	  lower = search + 1;
      else
	upper = search - 1;
    }
  return -1;
}
