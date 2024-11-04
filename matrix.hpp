#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <cstddef>

int **matrix(size_t m, size_t n);
void clear(int **t, size_t m);
bool enter(int **t, size_t m, size_t n);
void out(const int *const *t, size_t m, size_t n);

class Matrix
{
  size_t rows_; // rows
  size_t cols_; // cols
  int **data_;

public:
  Matrix(size_t rows, size_t cols);
  Matrix(const Matrix& other);
  ~Matrix();
  size_t getRows() const;
  size_t getCols() const;
  void fill(int value);
  void resize(size_t new_rows, size_t new_cols);

private:
  void create(size_t rows, size_t cols);
  void clear(size_t rows_to_clear);
};

#endif
