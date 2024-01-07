#ifndef HAMMER_HPP
#define HAMMER_HPP

#include "Tool.hpp"
#include <iostream>

class Hammer : public Tool {
    public :
        Hammer();
        Hammer(Hammer const & src);
        ~Hammer();
        Hammer & operator=(Hammer const & rhs);

        friend std::ostream & operator<<(std::ostream & o, Hammer const & rhs);
};

#endif // HAMMER_HPP