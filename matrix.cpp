#include "matrix.hpp"

#include <iostream>

void clear(int **t, size_t m) {
  for (size_t i = 0; i < m; i += 1) {
    delete[] t[i];
  }
  delete[] t;
}

int **create(size_t m, size_t n) {
  int **t = new int *[m];
  size_t created = 0;

  try {
    for (; created < m; created += 1) {
      t[created] = new int[n];
    }
  } catch (const std::bad_alloc &e) {
    clear(t, created);
    throw;
  }
  return t;
}

void enter(int **t, size_t m, size_t n) {
  for (size_t i = 0; i < m; i += 1) {
    for (size_t j = 0; j < n; j += 1) {
      std::cin >> t[i][j];
      if (!std::cin) {
        if (std::cin.eof()) {
          throw std::range_error("Unexpected end of file");
        } else {
          throw std::runtime_error("Input error");
        }
      }
    }
  }
}

void out(const int *const *t, size_t m, size_t n) {
  for (size_t i = 0; i < m; i += 1) {
    std::cout << t[i][0];
    for (size_t j = 1; j < n; j += 1) {
      std::cout << " " << t[i][j];
    }
    std::cout << "\n";
  }
}
