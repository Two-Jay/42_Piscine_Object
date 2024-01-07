#include "Statistic.hpp"

#include <iostream>

Statistic::Statistic(void) : _level(0), _exp(0), _maxExp(0) {
    this->setMaxExp();
}

Statistic::Statistic(int level, int exp) : _level(level), _exp(exp), _maxExp(0) {
    this->setMaxExp();
}

Statistic::Statistic(Statistic const & src) {
    *this = src;
}

Statistic::~Statistic(void) {
}

Statistic & Statistic::operator=(Statistic const & rhs) {
    if (this != &rhs) {
        this->_level = rhs.getLevel();
        this->_exp = rhs.getExp();
    }
    return *this;
}

int Statistic::getLevel(void) const {
    return this->_level;
}

int Statistic::getExp(void) const {
    return this->_exp;
}

void Statistic::levelUp() {
    this->_level++;
}

void Statistic::gainExp(int exp) {
    this->_exp += exp;
    if (this->_exp >= this->_maxExp) {
        this->levelUp();
        this->setMaxExp();
        // calculate the remaining exp
        this->_exp = this->_exp - this->_maxExp;
    }
}

void Statistic::setMaxExp() {
    this->_maxExp = this->_level * 100 + (this->_level * 50);
}

std::ostream & operator<<(std::ostream & o, Statistic const & rhs) {
    o << "Stat : [level = " << rhs.getLevel() << " / " << "exp = " << rhs.getExp() << "]" << std::endl;
    return o;
}



