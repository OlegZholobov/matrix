#include <iostream>
#include "matrix.hpp"
#include "getNumberOfOrderedRows.hpp"

int main()
{
    int **matrix = nullptr;
    int m = 0;
    int n = 0;
    if (!(std::cin >> m) || (m <= 0)){
        std::cerr << "ERROR: Invalid number of rows specified\n";
        return EXIT_FAILURE;
    }
    if (!(std::cin >> n) || (n <= 0)){
        std::cerr << "ERROR: Invalid number of columns specified\n";
        return EXIT_FAILURE;
    }

    try {
        matrix = create(m, n);
    }
    catch (const std::bad_alloc &e)
    {
        std::cerr << "ERROR: Memory not allocated for array\n";
        return EXIT_FAILURE;
    }

    try {
        enter(matrix, m, n);
    }
    catch(const std::range_error&) {
        std::cerr << "ERROR: Not enough matrix elements\n";
        clear(matrix, m);
        return EXIT_FAILURE;
    }
    catch(const std::runtime_error&) {
        std::cerr << "ERROR: Invalid matrix element\n";
        clear(matrix, m);
        return EXIT_FAILURE;
    }
    

    std::cout << "Number of ordered rows = " << getNumberOfOrderedRows(matrix, m, n) << "\n";

    clear(matrix, m);
    return EXIT_SUCCESS;
}
