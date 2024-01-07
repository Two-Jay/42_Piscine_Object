#ifndef SHOVEL_HPP
#define SHOVEL_HPP

#include "Tool.hpp"
#include <iostream>

class Shovel : public Tool {
    public :
        Shovel();
        Shovel(Shovel const & src);
        virtual ~Shovel();
        Shovel & operator=(Shovel const & rhs);

        virtual Tool *clone() const;

        friend std::ostream & operator<<(std::ostream & o, Shovel const & rhs);
};

#endif // SHOVEL_HPP