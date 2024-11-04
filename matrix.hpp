#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <cstddef>

int **create(size_t m, size_t n);
void clear(int **t, size_t m);
void enter(int **t, size_t m, size_t n);
void out(const int *const *t, size_t m, size_t n);

#endif
