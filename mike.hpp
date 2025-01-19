// math.hpp
#pragma once

// Vectors
#include "math/vector/VectorFloat4.hpp"
#include "math/vector/VectorFloat3.hpp"
#include "math/vector/VectorFloat2.hpp"

// Matrices
#include "math/matrix/MatrixFloat4x4.hpp"
#include "math/matrix/MatrixFloat3x3.hpp"
#include "math/matrix/MatrixFloat2x2.hpp"

// Geometry
#include "math/geometry/SegmentFloat3D.hpp"
#include "math/geometry/SegmentFloat2D.hpp"

// Utils
#include "math/scalarFloat.hpp"
#include "math/trigonometryFloat.hpp"

namespace math {

    // Shorthand
    typedef VectorFloat4 vecf4;
    typedef VectorFloat3 vecf3;
    typedef VectorFloat2 vecf2;

    typedef MatrixFloat4x4 matf4x4;
    typedef MatrixFloat3x3 matf3x3;
    typedef MatrixFloat2x2 matf2x2;

    typedef SegmentFloat3D segmentf3D;
    typedef SegmentFloat2D segmentf2D;

    // Defaults
    typedef vecf4 vec4;
    typedef vecf3 vec3;
    typedef vecf2 vec2;

    typedef matf4x4 mat4;
    typedef matf3x3 mat3;
    typedef matf2x2 mat2;

    typedef segmentf3D segment3D;
    typedef segmentf2D segment2D;
}
