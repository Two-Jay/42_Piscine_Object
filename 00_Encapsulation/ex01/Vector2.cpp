#include "Vector2.hpp"
#include <iostream>

Vector2::Vector2() {}

Vector2::Vector2(float x, float y) : _point(Point(x, y)){}

Vector2::Vector2(int x, int y)  : _point(Point(x, y)) {}

Vector2::Vector2(Point p) : _point(p) {}

const Point &Vector2::getPositionPoint(void) const {
    return _point;
}

std::ostream &operator<<(std::ostream &o, Vector2 const &rhs) {
    o << "Vector 2d - " <<  rhs.getPositionPoint();
    return o;
}