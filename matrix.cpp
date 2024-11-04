#include "matrix.hpp"
#include <iostream>

void clear(int **t, size_t m)
{
  for (size_t i = 0; i < m; i += 1)
  {
    delete[] t[i];
  }
  delete[] t;
}

int **matrix(size_t m, size_t n)
{
  int **t = new int *[m];
  size_t created = 0;

  try
  {
    for (; created < m; created += 1)
    {
      t[created] = new int[n];
    }
  }
  catch (const std::bad_alloc &e)
  {
    clear(t, created);
    throw;
  }
  return t;
}

bool enter(int **t, size_t m, size_t n)
{
  for (size_t i = 0; i < m; i += 1)
  {
    for (size_t j = 0; j < n; j += 1)
    {
      std::cin >> t[i][j];
      if (!std::cin)
      {
        std::cerr << "Not a number\n";
        return false;
      }
    }
  }
  return true;
}

void out(const int *const *t, size_t m, size_t n)
{
  for (size_t i = 0; i < m; i += 1)
  {
    std::cout << t[i][0];
    for (size_t j = 1; j < n; j += 1)
    {
      std::cout << " " << t[i][j];
    }
    std::cout << "\n";
  }
}

Matrix::Matrix(size_t rows, size_t cols) {
//  create(rows, cols);
  rows_ = rows;
  cols_ = cols;
  data_ = ::matrix(rows, cols);
}

Matrix::Matrix(const Matrix& other) {
  rows_ = other.rows_;
  cols_ = other.cols_;
  data_ = matrix(other.rows_, other.cols_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      data_[i][j] = other.data_[i][j];
    }
  }
}

Matrix::~Matrix() {
  clear(rows_);
}

size_t Matrix::getRows() const {
  return rows_;
}

size_t Matrix::getCols() const {
  return cols_;
}

void Matrix::fill(int value) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      data_[i][j] = value;
    }
  }
}

void Matrix::resize(size_t new_rows, size_t new_cols) {
  clear(rows_);
  create(new_rows, new_cols);
}
