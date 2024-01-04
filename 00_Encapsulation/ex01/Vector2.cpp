#include "Vector2.hpp"
#include <iostream>

Vector2::Vector2() {}

Vector2::Vector2(float x, float y) : _x(x), _y(y) {}

Vector2::Vector2(int x, int y)  : _x(static_cast<float>(x)), _y(static_cast<float>(y)) {}

float Vector2::getX() const {
    return _x;
}

float Vector2::getY() const {
    return _y;
}

std::ostream &operator<<(std::ostream &o, Vector2 const &rhs) {
    o << "V(" << rhs._x << "," << rhs._y << ")";
    return o;
}

bool Vector2::operator==(Vector2 const &rhs) const {
    return _x == rhs._x && _y == rhs._y;
}

bool Vector2::operator!=(Vector2 const &rhs) const {
    return !(*this == rhs);
}