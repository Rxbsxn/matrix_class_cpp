#pragma once

#include <ctime>
#include <fstream>
#include <iostream>

using namespace std;

template <class Type>
class Matrix
{

private:
  int rows, cols;
  Type **data;

public:

  Matrix(int rows = 1, int cols = 1) : rows(rows), cols(cols) {
    data = new Type * [rows];
    for (int i = 0; i < rows; i++) {
      data[i] = new Type[cols];

      for (int j = 0; j < cols; j++) {
        data[i][j] = rand() % 31;
      }
    }
  }

  ~Matrix() {
    if (data != nullptr) {
      for (int i = 0; i < rows; i++)
        delete[] data[i];

      delete[] data;
      data = nullptr;
    }
  }

  int getRows() {
    return this->rows;
  }

  int getCols() {
    return this->cols;
  }

  void saveToFile(string filename) {
    ofstream out(filename);
    out << *this;

    out.close();
  }
  
  double * operator[](int row) {
    return data[row];
  }

  Matrix operator +(Matrix &other) {
    int rows = this->getRows();
    int colums = this->getCols();

    for (size_t i = 0; i < rows; i++)
      for (size_t j = 0; j < cols; j++)
        this->data[i][j] += other[i][j];

    return *this;
  }
};
template <class Test>
ostream &operator << (ostream &out, Matrix<Test> &matrix) {

  for (size_t i = 0; i < matrix.getRows(); i++)
  {
    for (size_t j = 0; j < matrix.getCols(); j++)
      out << matrix[i][j] << '\t';

    out << endl;
  }

  return out;
}