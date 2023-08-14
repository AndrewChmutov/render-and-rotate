#include "shape3d.hpp"
#include <SDL_render.h>

// TO-DO
void Shape3D::rotateVector(vec3& vector3, double x_radian, double y_radian, double z_radian) {}


void Shape3D::setPixels(Screen& screen) const {
    // Put vertices
    for (const vec3& vector3 : vertices) {
        screen.putPixel(vector3.x, vector3.y);
    }

    // Put connections TO-DO
}