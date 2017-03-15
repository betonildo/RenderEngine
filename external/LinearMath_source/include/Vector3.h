#ifndef VECTOR3_H
#define VECTOR3_H

#include "linearmath_local_definitions.h"

struct Vector3 {

    union {
        struct {
            float x, y, z;
        };
        
        #ifdef USE_SSE
        __m128 _sse_var;
        #endif
    };
    

    inline Vector3() {

    }

    inline Vector3(float x, float y, float z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    inline Vector3(const Vector3& v) {
        (*this) = v;
    }

    inline Vector3 normalize() {        
        float mag = magnitude();
        return Vector3(x / mag, y / mag, z / mag);
    }

    inline float magnitude() {
        return sqrt(squaredMagnitude());
    }

    inline float squaredMagnitude() {
        return x * x + y * y + z * z;
    }
    
    inline friend float operator*(const Vector3& u, const Vector3& v) {
        return dot(u, v);
    }

    inline friend float dot(const Vector3& u, const Vector3& v) {
        return u.x * v.x + u.y * v.y + u.z * v.z;
    }

    inline friend Vector3& cross(const Vector3& u, const Vector3& v) {
        
        Vector3& r = (Vector3&)*(new Vector3());

        r.x = u.y * v.z - u.z * v.y;
        r.y = u.x * v.z - u.z * v.x;
        r.z = u.x * v.y - u.y * v.x;

        return r;
    }

    inline friend Vector3& operator*(const Vector3& u, const float& f) {
        
        Vector3& r = (Vector3&)*(new Vector3());
        
        r.x = u.x * f;
        r.y = u.y * f;
        r.z = u.z * f;
        
        return r;
    }

    inline friend Vector3& operator*( const float& f, const Vector3& u) {
        
        Vector3& r = (Vector3&)*(new Vector3());
        
        r.x = u.x * f;
        r.y = u.y * f;
        r.z = u.z * f;
        
        return r;
    }

    inline friend Vector3& operator+(const Vector3& u, const Vector3& v) {
        
        Vector3& r = (Vector3&)*(new Vector3());
        
        r.x = u.x + v.x;
        r.y = u.y + v.y;
        r.z = u.z + v.z;
        
        return r;
    }

    inline friend Vector3 operator-(const Vector3& u, const Vector3& v) {
        
        Vector3 r;
        
        r.x = u.x - v.x;
        r.y = u.y - v.y;
        r.z = u.z - v.z;
        
        return r;
    }

    inline Vector3& operator-() {
        x = -x;
        y = -y;
        z = -z;
        return *this;
    }

    inline Vector3& operator=(const Vector3& v) {

        x = v.x;
        y = v.y;
        z = v.z;
        
        return *this;
    }

    inline friend std::ostream& operator<<(std::ostream& os, const Vector3& v) {
      
        os << "[" << v.x << ", " << v.y << ", " << v.z << "]";
        
        return os;
    };
};

#endif /*VECTOR3_H*/