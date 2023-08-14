#include "coin.hpp"

Coin::Coin(double x, double y, double z, double radius, double width) {
    // Setup centroid
    centroid = vec3{x, y, z};

    // Reserve 360 vertices for each side (two cirles)
    vertices.reserve(720);

    // First
    for (int i = 0; i < 360; i++) {
        vertices.push_back(vec3{x + radius * std::cos(2*M_PI*i / 360), y + radius * std::sin(2*M_PI*i / 360), z - width / 2});
    }

    // Second
    for (int i = 0; i < 360; i++) {
        vertices.push_back(vec3{x + radius * std::cos(2*M_PI*i / 360), y + radius * std::sin(2*M_PI*i / 360), z + width / 2});
    }
}


void Coin::rotate(double x_radian, double y_radian, double z_radian) 
{
    // To calculate rotation around centroid instead of origin (0, 0, 0)
    // We have to "place" figure into origin
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