#include <iostream>
#include "Point.hpp"
#include "Vector2.hpp"

int main(int argc, char** argv) {
    (void)argc;
    (void)argv;

    Point a = Point();
    Point b = Point(42.42, 42.42);

    std::cout << a << std::endl;
    std::cout << b << std::endl;

    Vector2 va = Vector2(a);
    Vector2 vb = Vector2(b);

    std::cout << va << std::endl;
    std::cout << vb << std::endl;
    return 0;
}