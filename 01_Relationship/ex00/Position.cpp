#include "Position.hpp"

#include <iostream>

Position::Position(void) : _x(0), _y(0), _z(0) {
    return;
}

Position::Position(int x, int y, int z) : _x(x), _y(y), _z(z) {
    return;
}

Position::Position(Position const & src) {
    *this = src;
    return;
}

Position::~Position(void) {
    return;
}

Position & Position::operator=(Position const & rhs) {
    if (this != &rhs) {
        this->_x = rhs.getX();
        this->_y = rhs.getY();
        this->_z = rhs.getZ();
    }
    return *this;
}

int Position::getX(void) const {
    return this->_x;
}

int Position::getY(void) const {
    return this->_y;
}

int Position::getZ(void) const {
    return this->_z;
}

void Position::setX(int x) {
    this->_x = x;
}

void Position::setY(int y) {
    this->_y = y;
}

void Position::setZ(int z) {
    this->_z = z;
}

void Position::setXYZ(int x, int y, int z) {
    this->_x = x;
    this->_y = y;
    this->_z = z;
}

std::ostream & operator<<(std::ostream & o, Position const & rhs) {
    o << "Position - (" << rhs.getX() << ", " << rhs.getY() << ", " << rhs.getZ() << ")" << std::endl;
    return o;
}

