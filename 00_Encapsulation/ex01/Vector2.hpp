#ifndef VECTOR2_HPP
# define VECTOR2_HPP

#include "Point.hpp"

class Vector2 {
    private:
        Point _point;
        Vector2();

    public:
        Vector2(float x, float y);
        Vector2(int x, int y);
        Vector2(Point p);

        const Point &getPositionPoint(void) const;

        friend std::ostream &operator<<(std::ostream &o, Vector2 const &rhs);
};

#endif //VECTOR2_HPP