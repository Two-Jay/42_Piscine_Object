#include "Shovel.hpp"

Shovel::Shovel() : Tool() {
}

Shovel::Shovel(Shovel const & src) {
    *this = src;
}

Shovel::~Shovel() {
}

Shovel & Shovel::operator=(Shovel const & rhs) {
    if (this != &rhs) {
        this->_numberOfUse = rhs.getNumberOfUse();
    }
    return *this;
}

Tool *Shovel::clone() const {
    return new Shovel(*this);
}

std::ostream & operator<<(std::ostream & o, Shovel const & rhs) {
    o << "Shovel : [number of use = " << rhs.getNumberOfUse() << "]" << std::endl;
    return o;
}

