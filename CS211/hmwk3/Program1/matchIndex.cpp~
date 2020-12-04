/**
 * Assignment: Homework 3, Problem 1
 * Class: matchIndex.cpp
 * Author: Kevyn Higbee
 * Date Due: April 10, 2018
 */

#include <iostream>

using namespace std;

// recursive search function
int matchIndex(int, int[]);

int main()
{
  int arr1[19] = {-20, -15, -10, -8, -7, -6, -5, -3, 1, 2, 3, 4, 5, 6, 7, 8, 9, 15, 16};
  int arr2[10] = {-40, -20, -1, 1, 2, 3, 5, 7, 9, 12};
  int arr3[11] = {-5, -3, 2, 5, 6, 7, 8, 9, 15, 16, 20};
  int arr4[10] = {0, 1, 2, 3, 4 ,5, 6, 7, 8, 9};
  int key = 0;  // holds the value of the search value
  
  // first array test 
  cout << "Searching array 1" << endl;
  key = matchIndex(19, arr1);
  (key == -1) ? cout << "There are no matching indices" << endl : cout << "The matching index value is " << key << endl;
  // second array test
  cout << "Searching array 2" << endl;
  key = matchIndex(10, arr2);
  (key == -1) ? cout << "There are no matching indices" << endl : cout << "The matching index value is " << key << endl;
  // third array test
  cout << "Searching array 3" << endl;
  key = matchIndex(11, arr3);
  (key == -1) ? cout << "There are no matching indices" << endl : cout << "The matching index value is " << key << endl;
  // fourth array test
  cout << "Searching array 4" << endl;
  key = matchIndex(10, arr4);
  (key == -1) ? cout << "There are no matching indices" << endl : cout << "The matching index value is " << key << endl;

  return 0;
}

int matchIndex(int index, int arr[])
{
  if(index < 0)  // base case is index is < 0
    return -1;
  else
    if(arr[index] == index)
      return index;
    else
      return matchIndex(--index, arr);
}
