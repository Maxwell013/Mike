// SegmentFloat3D.hpp
#pragma once

#include "../vector/VectorFloat3.hpp"
#include "../scalarFloat.hpp"
#include "SegmentFloat2D.hpp"

namespace math {

    class alignas(16) SegmentFloat3D {

    public:

        union {
            struct { VectorFloat3 a, b; };
            struct { VectorFloat3 start, end; };
        };

        SegmentFloat3D(const VectorFloat3& p_end) : a(VectorFloat3::Zero()), b(p_end) {}

        SegmentFloat3D(const VectorFloat3& p_start, const VectorFloat3 p_end, const float p_width = 0.0f) : a(p_start), b(p_end) {}

        SegmentFloat3D(const SegmentFloat3D& p_segment) : a(p_segment.a), b(p_segment.b) {}

        SegmentFloat3D(const SegmentFloat2D& p_segment) : a(p_segment.a, 0.0f), b(p_segment.b, 0.0f) {}

        SegmentFloat3D& operator=(SegmentFloat3D& p_segment) {
            a = p_segment.a;
            b = p_segment.b;
            return *this;
        }

        SegmentFloat3D& operator=(SegmentFloat2D p_segment) {
            a = p_segment.a;
            b = p_segment.b;
            return *this;
        }

        float length() const {
            return a.distance(b);
        }

        VectorFloat3 vector() const {
            return a - b;
        }

        float distance(const VectorFloat3& p_point) const {
            const VectorFloat3 d = vector();
            const float t = clamp((p_point - a).dot(d.normalized()), 0.0f, 1.0f);
            const VectorFloat3 c = a + (d * t);
            return p_point.distance(c);
        }

        float distance(const SegmentFloat3D& p_segment) const {
            const VectorFloat3 d1 = vector();
            const VectorFloat3 d2 = p_segment.vector();
            const VectorFloat3 r = a - p_segment.a;

            const float l1 = d1.dot(d1);
            const float l2 = d2.dot(d2);
            const float r1 = d1.dot(r);
            const float r2 = d2.dot(r);
            const float dot = d1.dot(d2);

            const float den = l1 * l2 - dot * dot;

            if (isZero(den)) {
                VectorFloat3 c = d1.normalized() * (r.dot(d1));
                return r.distance(c);

            }
            const float t1 = clamp((dot * r1 -  r2 * l2) / den, 0.0f, 1.0f);
            const float t2 = clamp(( l1 * r1 - dot * r2) / den, 0.0f, 1.0f );

            const VectorFloat3 c1 = a + d1 * t1;
            const VectorFloat3 c2 = p_segment.a + d2 * t2;

            return c1.distance(c2);
        }
    };
} // namespace math
