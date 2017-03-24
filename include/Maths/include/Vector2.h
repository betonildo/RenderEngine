#ifndef VECTOR2_H
#define VECTOR2_H

#include "linearmath_local_definitions.h"

struct Vector2 {

    float x, y;

    inline Vector2() {

    }

    inline Vector2(float x, float y) {
        this->x = x;
        this->y = y;
    }

    inline Vector2(const Vector2& v) {
        *this = v;
    }

    inline float magnitude() {
        return sqrt(squaredMagnitude());
    }

    inline float squaredMagnitude() {
        return dot(*this, *this);
    }

    inline friend float operator*(const Vector2& u, const Vector2& v) {
        return dot(u, v);
    }

    inline friend float dot(const Vector2& u, const Vector2& v) {
        return u.x * v.x + u.y * v.y;
    }

    inline friend Vector2 operator+(Vector2& u, const Vector2& v) {
        return Vector2(u.x + v.x, u.y + v.y);
    }

    inline Vector2& operator+=(const Vector2& v) {
        x += v.x;
        y += v.y;
        return *this;
    }

    inline friend Vector2 operator*(const float& f, const Vector2& u) {
        return u * f;
    }

    inline friend Vector2 operator*(const Vector2& u, const float& f) {
        return Vector2(u.x * f, u.y * f);
    }    

    inline Vector2& operator=(const Vector2& v) {
        x = v.x;
        y = v.y;
        return *this;
    }

    inline friend bool operator!=(const Vector2& u, const Vector2& v) {
        return !(u == v);
    }

    inline friend bool operator==(const Vector2& u, const Vector2& v) {
        return abs(u.x - v.x) <= PRECISION && abs(u.y - v.y) <= PRECISION;
    }

    inline friend std::ostream& operator<<(std::ostream& os, const Vector2& u) {
        os << "[" << u.x << ", " << u.y << "]";
        return os;
    }
};

#endif /*VECTOR2_H*/