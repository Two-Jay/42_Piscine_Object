#include "Tool.hpp"

Tool::Tool() : _numberOfUse(0) {
}

Tool::Tool(Tool const & src) {
    *this = src;
}

Tool::~Tool() {
}

Tool & Tool::operator=(Tool const & rhs) {
    if (this != &rhs) {
        this->_numberOfUse = rhs.getNumberOfUse();
    }
    return *this;
}

unsigned int Tool::getNumberOfUse() const {
    return this->_numberOfUse;
}

void Tool::use() {
    this->_numberOfUse++;
}

std::ostream & operator<<(std::ostream & o, Tool const & rhs) {
    o << "Tool : [number of use = " << rhs.getNumberOfUse() << "]" << std::endl;
    return o;
}



