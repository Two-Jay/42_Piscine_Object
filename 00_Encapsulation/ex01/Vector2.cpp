#include "Vector2.hpp"
#include <iostream>

Vector2::Vector2() {}

Vector2::Vector2(float x, float y) : _x(x), _y(y) {}

Vector2::Vector2(int x, int y)  : _x(static_cast<float>(x)), _y(static_cast<float>(y)) {}

std::ostream &operator<<(std::ostream &o, Vector2 const &rhs) {
    o << "Vector 2d - " <<  "x: " << rhs._x << " y: " << rhs._y;
    return o;
}