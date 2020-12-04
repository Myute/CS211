/**
 * Assignment: Homework 3, Problem 1
 * Class: matchIndex.cpp
 * Author: Kevyn Higbee
 * Date Due: April 10, 2018
 */

#include <iostream>

using namespace std;

// recursive function
int matchIndex(int, int, int[]);

int main()
{
  int arr1[19] = {-20, -15, -10, -8, -7, -6, -5, -3, 1, 2, 3, 4, 5, 6, 7, 8, 9, 15, 16};
  int arr2[10] = {-40, -20, -1, 1, 2, 3, 5, 7, 9, 12};
  int arr3[11] = {-5, -3, 2, 5, 6, 7, 8, 9, 15, 16, 20};
  int arr4[10] = {0, 1, 2, 3, 4 ,5, 6, 7, 8, 9};
  int key = 0;

  cout << "Searching array 1 for '15'" << endl;
  key = matchIndex(15, 19, arr1);
  (key == -1) ? cout << "The value does not exist" << endl : cout << "The index of the value is " << key << endl;

  cout << "Searching array 2 for '99'" << endl;
  key = matchIndex(99, 10, arr2);
  (key == -1) ? cout << "The value does not exist" << endl : cout << "The index of the value is " << key << endl;

  cout << "Searching array 3 for '-5'" << endl;
  key = matchIndex(-5, 11, arr3);
  (key == -1) ? cout << "The value does not exist" << endl : cout << "The index of the value is " << key << endl;

  cout << "Searching array 4 for '9'" << endl;
  key = matchIndex(9, 10, arr4);
  (key == -1) ? cout << "The value does not exist" << endl : cout << "The index of the value is " << key << endl;

  return 0;
}

int matchIndex(int find, int index, int arr[])
{
  if(index < 0)
    return -1;
  else
    if(arr[index] == find)
      return index;
    else
      return matchIndex(find, --index, arr);
}
