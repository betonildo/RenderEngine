#ifndef VECTOR3_H
#define VECTOR3_H

#include "linearmath_local_definitions.h"


#pragma pack(push, 0)

struct Vector3 {

    float x, y, z;    

    inline Vector3() {
        x = y = z = 0;
    }

    inline Vector3(float x, float y, float z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    inline Vector3(const Vector3& v) {
        this->x = v.x;
        this->y = v.y;
        this->z = v.z;
    }

    inline Vector3 normalize() {        
        float mag = magnitude();
        mag = mag > 0 ? mag : 1;
        Vector3 result(x / mag, y / mag, z / mag);
        return result;
    }

    inline float magnitude() {
        float sqrd = squaredMagnitude();
        float sqrtRes = sqrtf(sqrd);
        return sqrtRes;
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

    inline float operator[](int index) {
        // ASSERT(index < 3, "Wrong address Vector3");
        return *(((float*)this) + index);
    }

    inline friend std::ostream& operator<<(std::ostream& os, const Vector3& v) {
      
        os << "[" << v.x << ", " << v.y << ", " << v.z << "]";
        
        return os;
    };
};

#pragma pack(pop)

#endif /*VECTOR3_H*/