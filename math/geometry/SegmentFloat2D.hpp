
// SegmentFloat2D.hpp
#pragma once

#include "../vector/VectorFloat2.hpp"
#include "../scalarFloat.hpp"

namespace math {

    class alignas(16) SegmentFloat2D {

    public:

        union {
            struct { VectorFloat2 a, b; };
            struct { VectorFloat2 start, end; };
        };

        SegmentFloat2D(const VectorFloat2& p_end) : a(VectorFloat2::Zero()), b(p_end) {}

        SegmentFloat2D(const VectorFloat2& p_start, const VectorFloat2 p_end, const float p_width = 0.0f) : a(p_start), b(p_end) {}

        SegmentFloat2D(const SegmentFloat2D& p_segment) : a(p_segment.a), b(p_segment.b) {}

        SegmentFloat2D& operator=(SegmentFloat2D& p_segment) {
            a = p_segment.a;
            b = p_segment.b;
            return *this;
        }

        SegmentFloat2D& operator=(SegmentFloat2D p_segment) {
            a = p_segment.a;
            b = p_segment.b;
            return *this;
        }

        float length() const {
            return a.distance(b);
        }

        VectorFloat2 vector() const {
            return a - b;
        }

        float distance(const VectorFloat2& p_point) const {
            const VectorFloat2 d = vector();
            const float t = clamp((p_point - a).dot(d.normalized()), 0.0f, 1.0f);
            const VectorFloat2 c = a + (d * t);
            return p_point.distance(c);
        }

        float distance(const SegmentFloat2D& p_segment) const {
            const VectorFloat2 d1 = vector();
            const VectorFloat2 d2 = p_segment.vector();
            const VectorFloat2 r = a - p_segment.a;

            const float l1 = d1.dot(d1);
            const float l2 = d2.dot(d2);
            const float r1 = d1.dot(r);
            const float r2 = d2.dot(r);
            const float dot = d1.dot(d2);

            const float den = l1 * l2 - dot * dot;

            if (isZero(den)) {
                VectorFloat2 c = d1.normalized() * (r.dot(d1));
                return r.distance(c);

            }
            const float t1 = clamp((dot * r1 -  r2 * l2) / den, 0.0f, 1.0f);
            const float t2 = clamp(( l1 * r1 - dot * r2) / den, 0.0f, 1.0f );

            const VectorFloat2 c1 = a + d1 * t1;
            const VectorFloat2 c2 = p_segment.a + d2 * t2;

            return c1.distance(c2);
        }
    };
} // namespace math
