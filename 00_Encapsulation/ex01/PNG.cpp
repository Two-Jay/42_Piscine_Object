#include "PNG.hpp"
#include "PNGHeader.hpp"

PNG::PNG() {}

PNG::PNG(int width, int height) : Image(width, height) {
    this->_header = new PNGHeader(width, height);
}

PNG::PNG(PNG const &src) {
    *this = src;
}

PNG::~PNG() {
    delete this->_header;
}

PNG &PNG::operator=(PNG const &rhs) {
    if (this != &rhs) {
        this->Image::operator=(rhs);
    }
    return *this;
}

// Compare this snippet from 00_Encapsulation/ex01/JPG.hpp: