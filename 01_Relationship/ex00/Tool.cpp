#include "Tool.hpp"
#include "Shovel.hpp"
#include "Hammer.hpp"

Tool::Tool() : _numberOfUse(0) {
}

Tool::Tool(Tool const & src) {
    *this = src;
}

Tool::~Tool() {
}

Tool &Tool::operator=(Tool const & rhs) {
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

void Tool::release() {
    this->_worker = NULL;
}

void Tool::take(Worker *worker) {
    this->_worker = worker;
}