#include "cube.hpp"
#include <utility>

Cube::Cube(double x, double y, double z, double size) {
    centroid = vec3{x, y, z};

    vertices.reserve(8);

    vertices.push_back(vec3{x - size / 2, y - size / 2, z - size / 2});
    vertices.push_back(vec3{x - size / 2, y - size / 2, z + size / 2});
    vertices.push_back(vec3{x - size / 2, y + size / 2, z - size / 2});
    vertices.push_back(vec3{x - size / 2, y + size / 2, z + size / 2});
    vertices.push_back(vec3{x + size / 2, y - size / 2, z - size / 2});
    vertices.push_back(vec3{x + size / 2, y - size / 2, z + size / 2});
    vertices.push_back(vec3{x + size / 2, y + size / 2, z - size / 2});
    vertices.push_back(vec3{x + size / 2, y + size / 2, z + size / 2});

    connections.reserve(12);
    
    connections.push_back(std::make_pair(0, 1));
    connections.push_back(std::make_pair(0, 2));
    connections.push_back(std::make_pair(0, 4));
    // connections.push_back(std::make_pair(0, 1));
    // connections.push_back(std::make_pair(0, 1));
    // connections.push_back(std::make_pair(0, 1));
    // connections.push_back(std::make_pair(0, 1));
    // connections.push_back(std::make_pair(0, 1));
    // connections.push_back(std::make_pair(0, 1));
    connections.push_back(std::make_pair(7, 6));
}


void Cube::rotate(double x_radian, double y_radian, double z_radian) {}