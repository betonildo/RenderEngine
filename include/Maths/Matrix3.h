#ifndef MATRIX3_H
#define MATRIX3_H

#include "linearmath_local_definitions.h"

class Matrix3 {

private:

    union {
        float rc[3][3];
        float ia[9];
    };
    
public:
    inline Matrix3() {

    }

    inline ~Matrix3() {
        
    }

    inline float* operator[](byte index) {
        return &ia[(index << 1) + index];
    }

    inline float& operator()(byte index) {
        return ia[index];
    }

    inline Matrix3& operator=(const Matrix3& n) {
        
        ia[0] = n.ia[0];
        ia[1] = n.ia[1];
        ia[2] = n.ia[2];
        ia[3] = n.ia[3];
        ia[4] = n.ia[4];
        ia[5] = n.ia[5];
        ia[6] = n.ia[6];
        ia[7] = n.ia[7];
        ia[8] = n.ia[8];

        return *this;
    }

    inline float* operator()(){
        return ia;
    }

    inline operator Matrix3& () {
        return *this;
    }

    inline friend std::ostream& operator<<(std::ostream& os, const Matrix3& m3) {
        os << "[" << m3.ia[0] << ", " << m3.ia[1] << ", " << m3.ia[2] << "]" << LF;
        os << "[" << m3.ia[3] << ", " << m3.ia[4] << ", " << m3.ia[5] << "]" << LF;
        os << "[" << m3.ia[6] << ", " << m3.ia[7] << ", " << m3.ia[8] << "]" << LF;
        return os;
    }
};

#endif /*MATRIX3_H*/