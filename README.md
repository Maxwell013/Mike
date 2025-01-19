# Mike
A lightweight math library for C++

This library is part of a long term project that aims to build a small game engine and break it down into various smaller projects.
This is the second library and is still under development.

## Version 0.1.0 - Beta release
- Major: Development
- Minor: Beta release
- Patch: Beta release

## Features
- Header only implementation
- Float vector classes (vecf2, vecf3, vecf4)
- Float matrix classes (matf2x2, matf3x3, matf4x4)
- Utility functions for floats (clamp, lerp, round, sqrt)
- Trigonometry functions for floats (radians, degrees, sin, cos, tan)

- (Development) Float Segment classes

## Usage
To get started with Mike, copy the `mike.hpp` file and the entire `math` directory from the repository and add it to your project.
Include the header files to your cpp files and use the any of the classes from the example bellow!

Example:
```C++
// test.cpp

#include "math/trigonometryFloat.hpp"
#include "mike.hpp"

math::mat4 camera(const float p_translate, const math::vec2& p_rotate) {
    math::mat4 projection = math::mat4::Perspective(math::HALF_PI, 4.0f / 3.0f, 1.0f, 100.f);

    math::mat4 view = math::mat4::Translation(0.0f, 0.0f, -p_translate);
    view = view * math::mat4::RotationY(p_rotate.y);
    view = view * math::mat4::RotationX(p_rotate.x);

    math::mat4 model = math::mat4::Scale(0.5f);

    return projection * view * model;
}
```

## Todo
- Segment intersections
- Geometry
  - 2D: line, triangle, circle, square
  - 3D: line, plane, sphere, cube
  - AABB, OBB, distance
- Quaternions
- SIMD instructions
- Int vectors
- Int matrices

## Changelog

### Version 0.1.0 - Beta release
- Changed the naming and branding of the library
- Changed class implementations for release

### Version Alpha 0.5
- Added basic scalar utility functions
- Added basic trig functions
- Added component wise multiplication for vectors
- Changed all cmath dependencies

### Version Aplpha 0.4
- Added basic float 3x3 and 2x2 matrices
- Added camera and transform support for float 4x4 matrix

### Version Alpha 0.3
- Added partial SIMD implementation

### Version Alpha 0.2
- Added basic float 4x4 matrix (mat4)

### Version Alpha 0.1
- Added basic float vectors (vec2, vec3, vec4)
