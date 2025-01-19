#pragma once
// VectorFloat4.hpp

#include <iostream>

#include "VectorFloat2.hpp"
#include "VectorFloat3.hpp"
#include "../scalarFloat.hpp"

namespace math {

    class alignas(16) VectorFloat4 {

    public:

        union {
            struct { float x, y, z, w; };
            struct { float r, g, b, a; };
            struct { float i, j, k, l; };
            float components[4];
        };

        static VectorFloat4 Zero() { return VectorFloat4(0.0f); }
        static VectorFloat4 X() { return VectorFloat4(1.0f, 0.0f, 0.0f, 0.0f); }
        static VectorFloat4 Y() { return VectorFloat4(0.0f, 1.0f, 0.0f, 0.0f); }
        static VectorFloat4 Z() { return VectorFloat4(0.0f, 0.0f, 1.0f, 0.0f); }
        static VectorFloat4 W() { return VectorFloat4(0.0f, 0.0f, 0.0f, 1.0f); }

        static VectorFloat4 Right() { return X(); }
        static VectorFloat4 Left() { return -X(); }
        static VectorFloat4 Up() { return Y(); }
        static VectorFloat4 Down() { return -Y(); }
        static VectorFloat4 Foward() { return Z(); }
        static VectorFloat4 Backward() { return -Z(); }

        VectorFloat4() : x(0.0f), y(0.0f), z(0.0f), w(1.0f) {}

        VectorFloat4(const float p_float) : x(p_float), y(p_float), z(p_float), w(p_float) {}

        VectorFloat4(const float p_x, const float p_y, const float p_z, const float p_w) : x(p_x), y(p_y), z(p_z), w(p_w) {}

        VectorFloat4(const VectorFloat4& p_vector) : x(p_vector.x), y(p_vector.y), z(p_vector.z), w(p_vector.w) {}

        VectorFloat4(const VectorFloat3& p_vector, const float p_w = 1.0f) : x(p_vector.x), y(p_vector.y), z(p_vector.z), w(p_w) {}

        VectorFloat4(const VectorFloat2& p_vector, const float p_z, const float p_w = 1.0f) : x(p_vector.x), y(p_vector.y), z(p_z), w(p_w) {}

        VectorFloat4& operator=(const VectorFloat4& p_vector) {
            x = p_vector.x;
            y = p_vector.y;
            z = p_vector.z;
            w = p_vector.w;
            return *this;
        }

        VectorFloat4& operator=(const VectorFloat3& p_vector) {
            x = p_vector.x;
            y = p_vector.y;
            z = p_vector.z;
            w = 1.0f;
            return *this;
        }

        VectorFloat4 operator+(const VectorFloat4& p_vector) const {
            return VectorFloat4(
                x + p_vector.x,
                y + p_vector.y,
                z + p_vector.z,
                w + p_vector.w
            );
        }

        VectorFloat4& operator+=(const VectorFloat4& p_vector) {
            x += p_vector.x;
            y += p_vector.y;
            z += p_vector.z;
            w += p_vector.w;
            return *this;
        }

        VectorFloat4 operator-(const VectorFloat4& p_vector) const {
            return VectorFloat4(
                x - p_vector.x,
                y - p_vector.y,
                z - p_vector.z,
                w + p_vector.w
            );
        }

        VectorFloat4 operator-() const { return VectorFloat4( -x, -y, -z, -w); }

        VectorFloat4& operator-=(const VectorFloat4& p_vector) {
            x -= p_vector.x;
            y -= p_vector.y;
            z -= p_vector.z;
            w -= p_vector.w;
            return *this;
        }

        VectorFloat4 operator*(const VectorFloat4& p_vector) const {
            return VectorFloat4(
                x * p_vector.x,
                y * p_vector.y,
                z * p_vector.z,
                w * p_vector.w
            );
        }

        VectorFloat4& operator*=(const VectorFloat4& p_vector) {
            x *= p_vector.x;
            y *= p_vector.y;
            z *= p_vector.z;
            w *= p_vector.w;
            return *this;
        }

        VectorFloat4 operator*(const float p_float) const {
            return VectorFloat4(
                x * p_float,
                y * p_float,
                z * p_float,
                w * p_float
            );
        }

        VectorFloat4& operator*=(const float p_float) {
            x *= p_float;
            y *= p_float;
            z *= p_float;
            w *= p_float;
            return *this;
        }

        VectorFloat4 operator/(const VectorFloat4& p_vector) const {
            return VectorFloat4(
                x / p_vector.x,
                y / p_vector.y,
                z / p_vector.z,
                w / p_vector.w
            );
        }

        VectorFloat4& operator/=(const VectorFloat4& p_vector) {
            x /= p_vector.x;
            y /= p_vector.y;
            z /= p_vector.z;
            w /= p_vector.w;
            return *this;
        }

        VectorFloat4 operator/(const float p_float) const {
            return VectorFloat4(
                x / p_float,
                y / p_float,
                z / p_float,
                w / p_float
            );
        }

        VectorFloat4& operator/=(const float p_float) {
            x /= p_float;
            y /= p_float;
            z /= p_float;
            w /= p_float;
            return *this;
        }

        float dot(const VectorFloat4& p_vector) const {
            return (
            x * p_vector.x +
            y * p_vector.y +
            z * p_vector.z +
            w * p_vector.w
            );
        }

        VectorFloat4 cross(const VectorFloat4& p_vector) const {
            return VectorFloat4(
                y * p_vector.z - z * p_vector.y,
                z * p_vector.x - x * p_vector.z,
                x * p_vector.y - y * p_vector.x,
                1.0f
            );
        }

        float magnitude() const {
            return sqrt(
                x*x +
                y*y +
                z*z +
                w*w
            );
        }

        VectorFloat4 normalized() const {
            const float m = magnitude();
            if (isZero(m)) return VectorFloat4(0, 0, 0, 0);
            return VectorFloat4(
                x / m,
                y / m,
                z / m,
                w / m
            );
        }

        VectorFloat4& normalize() {
            const float m = magnitude();
            if (isZero(m)) {
                x = 0; y = 0; z = 0; w = 0;
            } else {
                x /= m;
                y /= m;
                z /= m;
                w /= m;
            }
            return *this;
        }

        float distance(const VectorFloat4& p_vector) const {
            return VectorFloat4(
                x - p_vector.x,
                y - p_vector.y,
                z - p_vector.z,
                w - p_vector.w
            ).magnitude();
        }
    };

    inline bool operator==(const VectorFloat4& p_vectorA, const VectorFloat4& p_vectorB) {
        return (
            isZero(p_vectorA.x - p_vectorB.x) &&
            isZero(p_vectorA.y - p_vectorB.y) &&
            isZero(p_vectorA.z - p_vectorB.z) &&
            isZero(p_vectorA.w - p_vectorB.w)
        );
    }

    inline bool operator!=(const VectorFloat4& p_vectorA, const VectorFloat4& p_vectorB) {
        return (
            !isZero(p_vectorA.x - p_vectorB.x) ||
            !isZero(p_vectorA.y - p_vectorB.y) ||
            !isZero(p_vectorA.z - p_vectorB.z) ||
            !isZero(p_vectorA.w - p_vectorB.w)
        );
    }

    inline std::ostream& operator<<(std::ostream& p_ostream, const VectorFloat4& p_vector) {
        return p_ostream << "VectorFloat4(" << p_vector.x << ", " << p_vector.y << ", " << p_vector.z << ", " << p_vector.w << ")";
    }

} // namespace math
