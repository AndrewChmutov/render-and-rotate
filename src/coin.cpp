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