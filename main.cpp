#include <iostream>
#include "matrix.hpp"

int main()
{
    int **t = nullptr;
    size_t m = 0;
    size_t n = 0;
    std::cin >> m >> n;
    if (!std::cin){
        std::cerr << "A number expected\n";
        return EXIT_FAILURE;
    }
    std::cout << m << " " << n << "\n";
    try {
        t = matrix(m, n);    
    }
    catch (const std::bad_alloc &e)
    {
        std::cerr << "Out of memory\n";
        return EXIT_FAILURE;
    }

    if (enter(t, m, n))
        out(t, m, n);

    clear(t, m);
    return EXIT_SUCCESS;
}
