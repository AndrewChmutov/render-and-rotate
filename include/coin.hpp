#pragma once

#include "shape3d.hpp"
#include <utility>
#include <cmath>

class Coin : public Shape3D {
    vec3 centroid;

public:
    Coin(double x, double y, double z, double radius, double width);

    virtual void rotate(double x_radian, double y_radian, double z_radian) override;
};