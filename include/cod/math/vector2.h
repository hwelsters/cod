#ifndef MATH_VECTOR2_H
#define MATH_VECTOR2_H

#include <iostream>

struct Vector2
{
public:
    Vector2() : x(0), y(0) {}
    Vector2(float x, float y) : x(x), y(y) {}

    Vector2 operator+(Vector2 const &vector2) { return Vector2(this->x + vector2.x, this->y + vector2.y); }
    Vector2 operator-(Vector2 const &vector2) { return Vector2(this->x - vector2.x, this->y - vector2.y); }
    
    friend std::ostream &operator<<(std::ostream &os, const Vector2 &vector2)
    {
        os << "Vector2 :: " << vector2.x << " :: " << vector2.y << "\n";
        return os;
    }

    float x;
    float y;
};

#endif