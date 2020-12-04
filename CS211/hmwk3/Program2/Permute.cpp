/**
 * Assignment: Homework 3, Problem 2
 * Class: Permute.cpp
 * Author: Kevyn Higbee
 * Date Due: April 10, 2018
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// recursive function
vector<string> permute(string, int, vector<string>&);
// helper function that calls the recursive function
vector<string> permute(string);

int main()
{
  vector<string> v;

  // first test case
  v = permute("IS");
  cout << "Permutations for 'IS':" << endl;
  for(int i = 0; i < v.size(); i++)
    cout << v[i] << endl;
  // second test case
  v = permute("SUN");
  cout << "Permutations for 'SUN':" << endl;
  for(int i = 0; i < v.size(); i++)
    cout << v[i] << endl;
  // third test case
  v = permute("LIFE");
  cout << "Permutations for 'LIFE':" << endl;
  for(int i = 0; i < v.size(); i++)
    cout << v[i] << endl;
  // fourth test case
  v = permute("HOTEL");
  cout << "Permutations for 'HOTEL':" << endl;
  for(int i = 0; i < v.size(); i++)
    cout << v[i] << endl;
  
  return 0;
}

vector<string> permute(string str)
{
  vector<string> v;
  permute(str, 0, v); // call recursive function
  return v;
}

vector<string> permute(string str, int i, vector<string>& v)
{ 
  if(i == str.length()) // base case is index is the same as length of string
    v.push_back(str);
  else
    for(int j = i; j < str.length(); j++)
	{
          swap(str[i],str[j]);
	  permute(str, i+1, v);
          swap(str[i],str[j]);
	}

  return v;
}
