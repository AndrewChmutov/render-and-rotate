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
    vec3 centroid;

    // Implementation of rotating a vector is same for every geometric figure
    // Rotate vector by the respective angle
    void rotateVector(vec3& vector3, double x_radian, double y_radian, double z_radian);

public:
    // this may vary, depending on which point we are rotating around
    virtual void rotate(double x_radian, double y_radian, double z_radian);

    // Give view over vertices, mostly for screen
    const std::vector<vec3>& getVertices() const;

    // Give view over connections, mostly for screen
    const std::vector<std::pair<int, int>>& getConnections() const;
};