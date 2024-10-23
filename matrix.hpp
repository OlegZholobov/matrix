#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <cstddef>

int **matrix(size_t m, size_t n);
void clear(int **t, size_t m);
bool enter(int **t, size_t m, size_t n);
void out(const int *const *t, size_t m, size_t n);
#endif
