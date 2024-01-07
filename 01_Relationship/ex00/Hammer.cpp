#include "Hammer.hpp"

Hammer::Hammer() : Tool() {
}

Hammer::Hammer(Hammer const & src) {
    *this = src;
}

Hammer::~Hammer() {
}

Hammer & Hammer::operator=(Hammer const & rhs) {
    if (this != &rhs) {
        this->_numberOfUse = rhs.getNumberOfUse();
    }
    return *this;
}

Tool *Hammer::clone() const {
    return new Hammer(*this);
}

std::ostream & operator<<(std::ostream & o, Hammer const & rhs) {
    o << "Hammer : [number of use = " << rhs.getNumberOfUse() << "]" << std::endl;
    return o;
}