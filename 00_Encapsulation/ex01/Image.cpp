#include "Image.hpp"

Image::Image() {}

Image::Image(int width, int height) : _width(width), _height(height) {
}

Image::Image(Image const &src) {
    *this = src;
}

Image::~Image() {
}

Image &Image::operator=(Image const &rhs) {
    if (this != &rhs) {
        this->_width = rhs._width;
        this->_height = rhs._height;
    }
    return *this;
}

int Image::getWidth() const {
    return this->_width;
}

int Image::getHeight() const {
    return this->_height;
}