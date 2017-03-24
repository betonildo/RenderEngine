#ifndef QUATERNION_H
#define QUATERNION_H

#include "linearmath_local_definitions.h"
#include <Vector4.h>
#include <Vector3.h>

struct Quaternion {

    Vector3 v;
    float s;   

    inline Quaternion() {
        memset(this, 0, sizeof(Quaternion));
    }

    inline Quaternion(float x, float y, float z, float w) {
        v = Vector3(x, y, z).normalize();
        s = w;
    }

    inline Quaternion(Vector3& v, float s) {
        this->v = v.normalize();
        this->s = s;
    }

    inline Quaternion(Vector4& v) {
        this->v = ((Vector3)(Vector3&)v).normalize();
        s = v.w;
    }

    inline Quaternion(const Quaternion& q) {
        v = q.v;
        s = q.s;
    }

    inline friend Quaternion operator*(const Quaternion& p, const Quaternion& q) {
        
        Quaternion pq;

        Vector3 pv = p.v;
        Vector3 qv = q.v;

        float ps = p.s;
        float qs = q.s;

        pq.v = (ps * qv) + (qs * pv) + cross(pv, qv);
        pq.s = (ps * qs) - dot(pv, qv);

        return pq;
    }

    inline Quaternion& operator=(const Quaternion& q) {
        
        v = q.v;
        s = q.s;

        return *this;
    }
};

#endif /*QUATERNION_H*/