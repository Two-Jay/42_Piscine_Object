#ifndef VECTOR2_HPP
# define VECTOR2_HPP

#include <iostream>

class Vector2 {
    private:
        float _x;
        float _y;
        Vector2();

    public:
        Vector2(float x, float y);
        Vector2(int x, int y);

        friend std::ostream &operator<<(std::ostream &o, Vector2 const &rhs);
};

#endif //VECTOR2_HPP