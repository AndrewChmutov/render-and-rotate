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
    connections.push_back(std::make_pair(2, 3));
    connections.push_back(std::make_pair(4, 5));
    connections.push_back(std::make_pair(7, 3));
    connections.push_back(std::make_pair(7, 5));
    connections.push_back(std::make_pair(7, 6));
    connections.push_back(std::make_pair(4, 6));
    connections.push_back(std::make_pair(1, 3));
    connections.push_back(std::make_pair(1, 5));
    connections.push_back(std::make_pair(2, 6));
}


void Cube::rotate(double x_radian, double y_radian, double z_radian) 
{
    for (vec3& vertex : vertices) {
        vertex.x -= centroid.x;
        vertex.y -= centroid.y;
        vertex.z -= centroid.z;
        rotateVector(vertex, x_radian, y_radian, z_radian);
        vertex.x += centroid.x;
        vertex.y += centroid.y;
        vertex.z += centroid.z;
    }
}