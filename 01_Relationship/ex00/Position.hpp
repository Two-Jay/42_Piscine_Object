#ifndef POSITION_HPP
#define POSITION_HPP

#include <iostream>

class Position {
    private :
        int _x;
        int _y;
        int _z;
        Position();

    public :
        Position(int x, int y, int z);

        int getX() const;
        int getY() const;
        int getZ() const;
        void setX(int x);
        void setY(int y);
        void setZ(int z);
        
        void setXYZ(int x, int y, int z);
        void moveBy(int x, int y, int z);
        
        friend std::ostream & operator<<(std::ostream & o, Position const & rhs);
};

#endif // POSITION_HPP