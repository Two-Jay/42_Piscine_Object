#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) {
    return;
}

Point::Point(float const x, float const y) : _x(x), _y(y) {
    return;
}

Point::Point(Point const &src) {
    *this = src;
    return;
}

Point::~Point(void) {
    return;
}

Point &Point::operator=(Point const &rhs) {
    if (this != &rhs) {
        this->_x = rhs.getX();
        this->_y = rhs.getY();
    }
    return *this;
}

float Point::getX(void) const {
    return this->_x;
}

float Point::getY(void) const {
    return this->_y;
}

void Point::setX(float const x) {
    this->_x = x;
    return;
}

void Point::setY(float const y) {
    this->_y = y;
    return;
}

std::ostream &operator<<(std::ostream &o, Point const &rhs) {
    o << "Point(" << rhs.getX() << ", " << rhs.getY() << ")";
    return o;
}