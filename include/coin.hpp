#pragma once

#include "shape3d.hpp"
#include <utility>
#include <cmath>

class Coin : public Shape3D {
public:
    // Initialize by centroid
    Coin(double x, double y, double z, double radius, double width);
};