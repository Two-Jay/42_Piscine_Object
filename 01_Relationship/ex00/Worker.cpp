#include "Worker.hpp"
#include <iostream>
#include <iomanip>

Worker::Worker(Position &position, Statistic &statistic) : _position(position), _statistic(statistic) {
}

Worker::Worker(Worker const & src) {
    *this = src;
}

Worker::~Worker(void) {
}

Worker & Worker::operator=(Worker const & rhs) {
    if (this != &rhs) {
        this->_position = rhs.getPosition();
        this->_statistic = rhs.getStatistic();
    }
    return *this;
}

const Position &Worker::getPosition() const {
    return this->_position;
}

const Statistic &Worker::getStatistic() const {
    return this->_statistic;
}

void Worker::moveBy(int x, int y, int z) {
    this->_position.setXYZ(this->_position.getX() + x, this->_position.getY() + y, this->_position.getZ() + z);
}

#define TAB(x) std::setw(x * 4) << std::right << ""

std::ostream & operator<<(std::ostream & o, Worker const & rhs) {
    o << "Worker : {  " << std::endl;
    o << TAB(1) << "" << rhs.getPosition();
    o << TAB(1) << "" << rhs.getStatistic();
    o << "}" << std::endl;
    return o;
}