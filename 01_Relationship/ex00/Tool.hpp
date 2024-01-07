#ifndef TOOL_HPP
#define TOOL_HPP

#include "Worker.hpp"
#include <iostream>

class Worker;

class Tool {
    protected :
        unsigned int _numberOfUse;
        Worker *_worker;
    
    public :
        Tool();
        Tool(Tool const & src);
        virtual ~Tool();
        Tool & operator=(Tool const & rhs);

        unsigned int getNumberOfUse() const;
        void use();

        void release();
        void take(Worker *worker);

        virtual Tool *clone() const = 0;
};

#endif // TOOL_HPP