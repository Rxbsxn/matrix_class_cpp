#include "stdafx.h"
#include "Matrix.h"
#include <iostream>

using namespace std;

int main()
{
  Matrix<double> mat(2, 3);
  Matrix<double> mat2(2, 3);

  auto res = mat.operator+(mat2);

  cout << res; // Display in the console
  res.saveToFile("mat.txt"); // Save to given file

  system("pause");
  return 0;
}