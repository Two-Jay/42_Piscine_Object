#include "Worker.hpp"
#include "Shovel.hpp"
#include "Hammer.hpp"
#include <iostream>
#include <iomanip>

Worker::Worker(Position &position, Statistic &statistic) : _position(position), _statistic(statistic), _tool(NULL) {
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
        this->_tool = rhs._tool;
    }
    return *this;
}

const Position &Worker::getPosition() const {
    return this->_position;
}

const Statistic &Worker::getStatistic() const {
    return this->_statistic;
}

const Tool *Worker::getTool() const {
    return this->_tool;
}

void Worker::give(Tool *tool) {
    this->_tool = tool;
    tool->take(this);
}

void Worker::takeAway() {
    this->_tool = NULL;
}

void Worker::moveBy(int x, int y, int z) {
    this->_position.setXYZ(this->_position.getX() + x, this->_position.getY() + y, this->_position.getZ() + z);
}

#define TAB(x) std::setw(x * 4) << std::right << ""

bool isShovel(const Tool *tool) {
    return dynamic_cast<Shovel *>(const_cast<Tool*>(tool)) != NULL;
}

bool isHammer(const Tool *tool) {
    return dynamic_cast<Hammer *>(const_cast<Tool*>(tool)) != NULL;
}

std::ostream & operator<<(std::ostream & o, Worker const & rhs) {
    o << "Worker : {  " << std::endl;
    o << TAB(1) << "" << rhs.getPosition();
    o << TAB(1) << "" << rhs.getStatistic();

    o << TAB(1) << "" << "Tool : ";
    if (isShovel(rhs.getTool())) {
        o << "shovel" << " " << "with " << rhs.getTool()->getNumberOfUse() << " uses." << std::endl;
    } else if (isHammer(rhs.getTool())) {
        o << "hammer" << " " << "with " << rhs.getTool()->getNumberOfUse() << " uses." << std::endl;
    } else {
        o << "none" << std::endl;
    }
    o << "}" << std::endl;
    return o;
}

