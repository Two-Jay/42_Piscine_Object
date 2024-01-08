#ifndef WORKER_HPP
#define WORKER_HPP

#include <iostream>
#include "Position.hpp"
#include "Statistic.hpp"
#include "Tool.hpp"

class Tool;

class Worker {
    private :
        Position _position;
        Statistic _statistic;
        Tool *_tool;
        Worker();

    public :
        Worker(Position &position, Statistic &statistic);
        Worker(Worker const & src);
        ~Worker();
        Worker & operator=(Worker const & rhs);

        const Position &getPosition() const;
        const Statistic &getStatistic() const;
        const Tool *getTool() const;

        template <typename ToolType>
        const ToolType *getTool() const;

        void moveBy(int x, int y, int z);
        void give(Tool *tool);
        void takeAway();

        void work();
        
        friend std::ostream & operator<<(std::ostream & o, Worker const & rhs);
};

#endif // WORKER_HPP