#define DEBUG
#include "linearmath_local_definitions.h"
#include <Debug.h>
#include <Vector4.h>
#include <Quaternion.h>

#ifndef MATRIX4_H
#define MATRIX4_H

struct Quaternion;

class Matrix4 {

public:

    union {
        float m_1d[16];
        float m_2d[4][4];
        #ifdef USE_SSE
        __m128 m_rows[4];
        #endif
        Vector4 m_vecrows[4];
    };

    inline Matrix4() {

    }

    inline Matrix4(float d) {
        clear();

        m_2d[0][0] = d;
        m_2d[1][1] = d;
        m_2d[2][2] = d;
        m_2d[3][3] = d;
    }

    inline Matrix4(float matrix[16]) {
        memcpy(m_1d, matrix, sizeof(float) * 16);
    }

    inline Matrix4(const Matrix4& m) {
        memcpy(this, &m, sizeof(Matrix4));
    }

    inline void turnIdentity() {

        clear();

        m_2d[0][0] = 1;
        m_2d[1][1] = 1;
        m_2d[2][2] = 1;
        m_2d[3][3] = 1;
    }

    inline void turnTransversal() {

        std::swap(m_2d[1][0], m_2d[0][1]);
        std::swap(m_2d[2][0], m_2d[0][2]);
        std::swap(m_2d[3][0], m_2d[0][3]);
        std::swap(m_2d[2][1], m_2d[1][2]);
        std::swap(m_2d[3][1], m_2d[1][3]);
        std::swap(m_2d[3][2], m_2d[2][3]);
    }

    inline void clear() {
        memset(m_1d, 0, sizeof(Matrix4));
    }

    inline float* operator[](int index) {
        ASSERT(index < 4, "matrix4 vector index out of bounds");
        return m_2d[index];
    }

    inline float& operator()(int rowIdx, int colIdx) {
        ASSERT(rowIdx < 4 && colIdx < 4, "matrix4 access out of bounds");

        return m_2d[rowIdx][colIdx];
    }

    inline float* operator()() {
        return m_1d;
    }

    inline friend Matrix4 operator*(const Matrix4& m1, const Matrix4& m2) {
        
        Matrix4 mr;

        mr.m_vecrows[0] = m1.m_vecrows[0] * m2;
        mr.m_vecrows[1] = m1.m_vecrows[1] * m2;
        mr.m_vecrows[2] = m1.m_vecrows[2] * m2;
        mr.m_vecrows[3] = m1.m_vecrows[3] * m2;

        return mr;
    }

    inline Matrix4& operator*=(const Matrix4& m1) {
        
        m_vecrows[0] = m1.m_vecrows[0] * (*this);
        m_vecrows[1] = m1.m_vecrows[1] * (*this);
        m_vecrows[2] = m1.m_vecrows[2] * (*this);
        m_vecrows[3] = m1.m_vecrows[3] * (*this);

        return *this;
    }

    inline friend Vector4 operator*(const Vector4& u, const Matrix4& m) {
        
        Vector4 v;

        #ifdef USE_SSE
            v._sse_var = mulVectorMatrixFinal(u._sse_var, m.m_rows);
        #else
            Vector4 vTemp0 = m.m_vecrows[0] * u.x;
            Vector4 vTemp1 = m.m_vecrows[1] * u.y;
            Vector4 vTemp2 = m.m_vecrows[2] * u.z;
            Vector4 vTemp3 = m.m_vecrows[3] * u.w;
            v = vTemp0 + vTemp1 + vTemp2 + vTemp3;
        #endif
        
        return v;
    }
    

    inline Matrix4& operator=(const Matrix4& mo) {
        m_vecrows[0] = mo.m_vecrows[0];
        m_vecrows[1] = mo.m_vecrows[1];
        m_vecrows[2] = mo.m_vecrows[2];
        m_vecrows[3] = mo.m_vecrows[3];
        return *this;
    }

    inline friend bool operator==(const Matrix4& m1, const Matrix4& m2) {
        return (m1.m_vecrows[0] == m2.m_vecrows[0] &&
                m1.m_vecrows[1] == m2.m_vecrows[1] &&
                m1.m_vecrows[2] == m2.m_vecrows[2] &&
                m1.m_vecrows[3] == m2.m_vecrows[3]);
    }

    static inline Matrix4 Rotation(Quaternion& q) {

		Matrix4 result(1.0);

		float qx, qy, qz, qw, qx2, qy2, qz2, qxqx2, qyqy2, qzqz2, qxqy2, qyqz2, qzqw2, qxqz2, qyqw2, qxqw2;
		qx = q.v.x;
		qy = q.v.y;
		qz = q.v.z;
		qw = q.s;
		qx2 = (qx + qx);
		qy2 = (qy + qy);
		qz2 = (qz + qz);
		qxqx2 = (qx * qx2);
		qxqy2 = (qx * qy2);
		qxqz2 = (qx * qz2);
		qxqw2 = (qw * qx2);
		qyqy2 = (qy * qy2);
		qyqz2 = (qy * qz2);
		qyqw2 = (qw * qy2);
		qzqz2 = (qz * qz2);
		qzqw2 = (qw * qz2);

		result.m_vecrows[0] = Vector4(((1.0f - qyqy2) - qzqz2), (qxqy2 - qzqw2), (qxqz2 + qyqw2), 0.0f);
		result.m_vecrows[1] = Vector4((qxqy2 + qzqw2), ((1.0f - qxqx2) - qzqz2), (qyqz2 - qxqw2), 0.0f);
		result.m_vecrows[2] = Vector4((qxqz2 - qyqw2), (qyqz2 + qxqw2), ((1.0f - qxqx2) - qyqy2), 0.0f);
		return result;
    }

    static inline Matrix4 Translation(const Vector3& position) {
        
        Matrix4 m(1.0f);
        m[0][3] = position.x;
        m[1][3] = position.y;
        m[2][3] = position.z;
        return m;
    }

    static inline Matrix4 Scale(const Vector3& scale) {
        
        Matrix4 m(1.0f);
        m[0][0] = scale.x;
        m[1][1] = scale.y;
        m[2][2] = scale.z;
        return m;
    }

    inline friend std::ostream& operator<<(std::ostream& os, const Matrix4& m) {
        
        os << m.m_vecrows[0] << "\n";
        os << m.m_vecrows[1] << "\n";
        os << m.m_vecrows[2] << "\n";
        os << m.m_vecrows[3] << "\n";

        return os;
    }

    inline static Matrix4 lookAt(Vector3 eye, Vector3 target, Vector3 up) {

        Vector3 vz((eye - target).normalize());
        Vector3 vx(cross(up, vz).normalize());
        // vy doesn't need to be normalized because it's a cross
        // product of 2 normalized vectors
        Vector3 vy(cross(vz, vx));
        float matrix[] = {
            vx.x, vx.y, vx.z, 0,
            vy.x, vy.y, vy.z, 0,
            vz.x, vz.y, vz.z, 0,
            -dot(vx, eye), -dot(vy, eye), -dot(vz, eye), 1,
        };

        Matrix4 inverseViewMatrix(matrix);
        return inverseViewMatrix;
    }

    inline static Matrix4 orthoProjection(float left, float right, float bottom, float top, float Znear, float Zfar) {

            Matrix4 orthomatrix(1.0f);

            orthomatrix[0][0] = 2.0f / (right - left);
            
            orthomatrix[1][1] = 2.0f / (top - bottom);
            
            orthomatrix[2][2] = 2.0f / (Znear-Zfar);
 
            orthomatrix[3][0] = (left + right) / (left - right);
            orthomatrix[3][1] = (bottom + top) / (bottom - top);
            orthomatrix[3][2] = (Zfar + Znear) / (Zfar - Znear);
            orthomatrix[3][3] = 1;

            return orthomatrix;
    }
};

#endif /*MATRIX4_H*/