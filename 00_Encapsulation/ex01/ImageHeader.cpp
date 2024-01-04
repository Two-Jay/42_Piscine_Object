#include "ImageHeader.hpp"

ImageHeader::ImageHeader() {}

ImageHeader::ImageHeader(int width, int height) : _width(width), _height(height) {
}

ImageHeader::ImageHeader(ImageHeader const &src) {
    *this = src;
}

ImageHeader::~ImageHeader() {
}

ImageHeader &ImageHeader::operator=(ImageHeader const &rhs) {
    if (this != &rhs) {
        this->_width = rhs._width;
        this->_height = rhs._height;
    }
    return *this;
}

int ImageHeader::getWidth() const {
    return this->_width;
}

int ImageHeader::getHeight() const {
    return this->_height;
}

