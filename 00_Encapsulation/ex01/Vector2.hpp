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

        float getX() const;
        float getY() const;
        bool operator==(Vector2 const &rhs) const;
        bool operator!=(Vector2 const &rhs) const;
        friend std::ostream &operator<<(std::ostream &o, Vector2 const &rhs);
};

#endif //VECTOR2_HPP