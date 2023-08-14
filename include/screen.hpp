#pragma once

// C++ standard libraries
#include <stdexcept>
#include <vector>


// SDL libraries
#include <SDL2/SDL.h>


// Implemented structures
#include "structures.hpp"

class Screen {
    SDL_Window* window;
    SDL_Renderer* renderer;

    // Pixels to show in current frame
    std::vector<vec2> pixels;

public:
    Screen(int width, int height);

    // Handle input
    SDL_EventType input();

    // Append pixel for drawing in the frame
    void putPixel(double x, double y);

    // Show frame
    void show();

    // Clear pixels
    void clear();

    ~Screen();
};