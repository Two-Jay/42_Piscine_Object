#include "PNGHeader.hpp"

PNGHeader::PNGHeader() {}

PNGHeader::PNGHeader(int width, int height) : ImageHeader(width, height) {
}

PNGHeader::PNGHeader(PNGHeader const &src) {
    *this = src;
}

PNGHeader::~PNGHeader() {
}

PNGHeader &PNGHeader::operator=(PNGHeader const &rhs) {
    if (this != &rhs) {
        this->_width = rhs._width;
        this->_height = rhs._height;
    }
    return *this;
}

unsigned char *PNGHeader::generateHeader() {
    unsigned char *header = new unsigned char[8];
    header[0] = 0x89;
    header[1] = 0x50;
    header[2] = 0x4E;
    header[3] = 0x47;
    header[4] = 0x0D;
    header[5] = 0x0A;
    header[6] = 0x1A;
    header[7] = 0x0A;
    return header;
}