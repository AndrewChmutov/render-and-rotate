#include "coin.hpp"

Coin::Coin(double x, double y, double z, double radius, double width) {
    centroid = vec3{x, y, z};
    vertices.reserve(720);
    for (int i = 0; i < 360; i++) {
        vertices.push_back(vec3{x + radius * std::cos(2*M_PI*i / 360), y + radius * std::sin(2*M_PI*i / 360), z - width / 2});
    }

    for (int i = 0; i < 360; i++) {
        vertices.push_back(vec3{x + radius * std::cos(2*M_PI*i / 360), y + radius * std::sin(2*M_PI*i / 360), z + width / 2});
    }
}


void Coin::rotate(double x_radian, double y_radian, double z_radian) 
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