#pragma once

// C++ standard libraries
#include <vector>
#include <utility>
#include <numeric>

// User build libraries
#include "structures.hpp"

class Shape3D {
protected:
    std::vector<vec3> vertices;
    std::vector<std::pair<int, int>> connections;

    // Implementation of rotating a vector is same for every geometric figure
    // Rotate vector by the respective angle
    void rotateVector(vec3& vector3, double x_radian, double y_radian, double z_radian);

    // In theory, this is not obligatory, but for this example it can be
    // Connect all the vertivces with lines according to the vector of connections
    // virtual void connect(Screen& screen) const = 0;

public:
    // this may vary, depending on which point we are rotating around
    virtual void rotate(double x_radian, double y_radian, double z_radian) = 0;

    const std::vector<vec3>& getVertices() const;

    const std::vector<std::pair<int, int>>& getConnections() const;

    // Scatter vertices and connect
    // void setPixels(Screen& screen) const;
};