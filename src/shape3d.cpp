#include "shape3d.hpp"
#include <SDL_render.h>

// TO-DO
void Shape3D::rotateVector(vec3& vector3, double x_radian, double y_radian, double z_radian) {
    double temp;

    // Rotating around X axis
    temp = vector3.y;
    vector3.y = temp * cos(x_radian) - vector3.z * sin(x_radian);
    vector3.z = temp * sin(x_radian) + vector3.z * cos(x_radian);

    // Rotating around Y axis
    temp = vector3.x;
    vector3.x = temp * cos(y_radian) - vector3.z * sin(y_radian);
    vector3.z = temp * sin(y_radian) + vector3.z * cos(y_radian);


    // Rotating around Z axis
    temp = vector3.x;
    vector3.x = temp * cos(z_radian) - vector3.y * sin(z_radian);
    vector3.y = temp * sin(z_radian) + vector3.y * cos(z_radian);
}


const std::vector<vec3>& Shape3D::getVertices() const {
    return vertices;
}


const std::vector<std::pair<int, int>>& Shape3D::getConnections() const {
    return connections;
}
// void Shape3D::setPixels(Screen& screen) const {
//     // Put vertices
//     for (const vec3& vector3 : vertices) {
//         screen.putPixel(vector3.x, vector3.y);
//     }

//     // Put connections TO-DO
// }