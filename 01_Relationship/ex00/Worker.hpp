#ifndef WORKER_HPP
#define WORKER_HPP

#include <iostream>
#include "Position.hpp"
#include "Statistic.hpp"

class Worker {
    private :
        Position _position;
        Statistic _statistic;
        Worker();

    public :
        Worker(Position &position, Statistic &statistic);
        Worker(Worker const & src);
        ~Worker();
        Worker & operator=(Worker const & rhs);

        const Position &getPosition() const;
        const Statistic &getStatistic() const;

        void moveBy(int x, int y, int z);
        
        friend std::ostream & operator<<(std::ostream & o, Worker const & rhs);
};

#endif // WORKER_HPP