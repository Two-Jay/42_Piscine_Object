#ifndef POINT_HPP
# define POINT_HPP

#include <iostream>

class Point {
    private :
        float _x;
        float _y;
    
    public :
        Point();
        Point(float const x, float const y);
        Point(Point const &src);
        ~Point();

        Point &operator=(Point const &rhs);

        float getX() const;
        float getY() const;

        void setX(float const x);
        void setY(float const y);
        
        friend std::ostream &operator<<(std::ostream &o, Point const &rhs);
};



#endif //POINT_HPP