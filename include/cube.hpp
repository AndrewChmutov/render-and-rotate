#pragma once

#include "shape3d.hpp"

class Cube : public Shape3D {
    // Store center of the cube
    vec3 centroid;

public:
    // Place by giving centroid
    Cube(double x, double y, double z, double size);

    virtual void rotate(double x_radian, double y_radian, double z_radian) override;
};