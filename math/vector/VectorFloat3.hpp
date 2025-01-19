#pragma once
// VectorFloat3.hpp

#include <iostream>

#include "VectorFloat2.hpp"
#include "../scalarFloat.hpp"

namespace math {

    class alignas(16) VectorFloat3 {

    public:

        union {
            struct { float x, y, z; };
            struct { float r, g, b; };
            struct { float i, j, k; };
            float components[3];
        };

        static VectorFloat3 Zero() { return VectorFloat3(0.0f); }
        static VectorFloat3 X() { return VectorFloat3(1.0f, 0.0f, 0.0f); }
        static VectorFloat3 Y() { return VectorFloat3(0.0f, 1.0f, 0.0f); }
        static VectorFloat3 Z() { return VectorFloat3(0.0f, 0.0f, 1.0f); }

        static VectorFloat3 Right() { return X(); }
        static VectorFloat3 Left() { return -X(); }
        static VectorFloat3 Up() { return Y(); }
        static VectorFloat3 Down() { return -Y(); }
        static VectorFloat3 Foward() { return Z(); }
        static VectorFloat3 Backward() { return -Z(); }

        VectorFloat3() : x(0.0f), y(0.0f), z(1.0f) {}

        VectorFloat3(const float p_float) : x(p_float), y(p_float), z(p_float) {}

        VectorFloat3(const float p_x, const float p_y, const float p_z) : x(p_x), y(p_y), z(p_z) {}

        VectorFloat3(const VectorFloat3& p_vector) : x(p_vector.x), y(p_vector.y), z(p_vector.z) {}

        VectorFloat3(const VectorFloat2& p_vector, const float p_z = 1.0f) : x(p_vector.x), y(p_vector.y), z(p_z) {}

        VectorFloat3& operator=(const VectorFloat3& p_vector) {
            x = p_vector.x;
            y = p_vector.y;
            z = p_vector.z;
            return *this;
        }

        VectorFloat3& operator=(const VectorFloat2& p_vector) {
            x = p_vector.x;
            y = p_vector.y;
            z = 1.0f;
            return *this;
        }

        VectorFloat3 operator+(const VectorFloat3& p_vector) const {
            return VectorFloat3(
                x + p_vector.x,
                y + p_vector.y,
                z + p_vector.z
            );
        }

        VectorFloat3& operator+=(const VectorFloat3& p_vector) {
            x += p_vector.x;
            y += p_vector.y;
            z += p_vector.z;
            return *this;
        }

        VectorFloat3 operator-(const VectorFloat3& p_vector) const {
            return VectorFloat3(
                x - p_vector.x,
                y - p_vector.y,
                z - p_vector.z
            );
        }

        VectorFloat3 operator-() const { return VectorFloat3( -x, -y, -z); }

        VectorFloat3& operator-=(const VectorFloat3& p_vector) {
            x -= p_vector.x;
            y -= p_vector.y;
            z -= p_vector.z;
            return *this;
        }

        VectorFloat3 operator*(const VectorFloat3& p_vector) const {
            return VectorFloat3(
                x * p_vector.x,
                y * p_vector.y,
                z * p_vector.z
            );
        }

        VectorFloat3& operator*=(const VectorFloat3& p_vector) {
            x *= p_vector.x;
            y *= p_vector.y;
            z *= p_vector.z;
            return *this;
        }

        VectorFloat3 operator*(const float p_float) const {
            return VectorFloat3(
                x * p_float,
                y * p_float,
                z * p_float
            );
        }

        VectorFloat3& operator*=(const float p_float) {
            x *= p_float;
            y *= p_float;
            z *= p_float;
            return *this;
        }

        VectorFloat3 operator/(const VectorFloat3& p_vector) const {
            return VectorFloat3(
                x / p_vector.x,
                y / p_vector.y,
                z / p_vector.z
            );
        }

        VectorFloat3& operator/=(const VectorFloat3& p_vector) {
            x /= p_vector.x;
            y /= p_vector.y;
            z /= p_vector.z;
            return *this;
        }

        VectorFloat3 operator/(const float p_float) const {
            return VectorFloat3(
                x / p_float,
                y / p_float,
                z / p_float
            );
        }

        VectorFloat3& operator/=(const float p_float) {
            x /= p_float;
            y /= p_float;
            z /= p_float;
            return *this;
        }

        float dot(const VectorFloat3& p_vector) const {
            return (
            x * p_vector.x +
            y * p_vector.y +
            z * p_vector.z
            );
        }

        VectorFloat3 cross(const VectorFloat3& p_vector) const {
            return VectorFloat3(
                y * p_vector.z - z * p_vector.y,
                z * p_vector.x - x * p_vector.z,
                x * p_vector.y - y * p_vector.x
            );
        }

        float magnitude() const {
            return sqrt(
                x*x +
                y*y +
                z*z
            );
        }

        VectorFloat3 normalized() const {
            const float m = magnitude();
            if (isZero(m)) return VectorFloat3(0, 0, 0);
            return VectorFloat3(
                x / m,
                y / m,
                z / m
            );
        }

        VectorFloat3& normalize() {
            const float m = magnitude();
            if (isZero(m)) {
                x = 0; y = 0; z = 0;
            } else {
                x /= m;
                y /= m;
                z /= m;
            }
            return *this;
        }

        float distance(const VectorFloat3& p_vector) const {
            return VectorFloat3(
                x - p_vector.x,
                y - p_vector.y,
                z - p_vector.z
            ).magnitude();
        }
    };

    inline bool operator==(const VectorFloat3& p_vectorA, const VectorFloat3& p_vectorB) {
        return (
            isZero(p_vectorA.x - p_vectorB.x) &&
            isZero(p_vectorA.y - p_vectorB.y) &&
            isZero(p_vectorA.z - p_vectorB.z)
        );
    }

    inline bool operator!=(const VectorFloat3& p_vectorA, const VectorFloat3& p_vectorB) {
        return (
            !isZero(p_vectorA.x - p_vectorB.x) ||
            !isZero(p_vectorA.y - p_vectorB.y) ||
            !isZero(p_vectorA.z - p_vectorB.z)
        );
    }

    inline std::ostream& operator<<(std::ostream& p_ostream, const VectorFloat3& p_vector) {
        return p_ostream << "VectorFloat3(" << p_vector.x << ", " << p_vector.y << ", " << p_vector.z << ")";
    }

} // namespace math
