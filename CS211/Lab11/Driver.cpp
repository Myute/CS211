#include <iostream>
#include <fstream>

using namespace std;

class Matrix
{
  // Make the stand alone << and >> functions friends of the Matrix class
  friend ostream& operator<<(ostream& os, const Matrix& m);
  friend istream& operator>>(istream& ifs, Matrix& m);

private:
  int M [4][4]; // 4 by 4 matrix of integers
public:
  Matrix( ); // default constructor

  // Write the function prototype for the postfix operator here
  Matrix operator--(int dummy);

};
Matrix::Matrix()
{
  for (int i=0; i< 4; i++)
    for (int j=0; j<4; j++)
      M[i][j]=0;
}
Matrix Matrix::operator--(int dummy)
{
  Matrix tmp;
  tmp = *this;
  for(int i = 0; i < 4; i++)
    for(int z = 0; z < 4; z++)
      M[i][z]--;
  return tmp;
}

// Implement the overloaded post decrement member function here
ostream& operator<<(ostream& os, const Matrix& m);
istream& operator>>(istream& is, Matrix& m);
// Implement the overloaded << operator here

// Implement the overloaded >> operator here

int main()
{
  Matrix A, B;

  ifstream fin;
  fin.open("matrix.txt");
  // Call the << operator to display the Matrix A
  cout << A << endl;
  // Call the overloaded >> operator to grab information from a file into A
  fin >> A;
  // Call the << operator to display the Matrix A
  cout << A << endl;
  // Call the overloaded postfix decrement to decrement A and store it in B
  cout << A-- << endl;
  //B = A;
  // Call he << operator to display the Matrix B
  cout << A << endl;

  return 0;
}

ostream& operator<<(ostream& os, const Matrix& m)
{
  for(int i = 0; i < 4; i++)
    {
    for(int z = 0; z < 4; z++)
      os << m.M[i][z] << " ";
    os << endl;
    }
  return os;
}
istream& operator>>(istream& ifs, Matrix& m)
{
  for(int i = 0; i < 4; i++)
    for(int z = 0; z < 4; z++)
      ifs >> m.M[i][z];
  return ifs;
}
