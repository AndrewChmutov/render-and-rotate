#pragma once

#include "shape3d.hpp"

class Cube : public Shape3D {
public:
    // Place by giving centroid
    Cube(double x, double y, double z, double size);
};