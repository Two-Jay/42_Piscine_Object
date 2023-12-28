#include <iostream>
#include "Point.hpp"

int main(int argc, char** argv) {
    (void)argc;
    (void)argv;

    Point a = Point();
    Point b = Point(42.42, 42.42);

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    return 0;
}