#pragma once

// C++ standard libraries
#include <cstdint>
#include <stdexcept>
#include <vector>


// SDL libraries
#include <SDL2/SDL.h>


// Implemented libraries
#include "structures.hpp"
#include "shape3d.hpp"

class Screen {
    // SDL pointers
    SDL_Window* window;
    SDL_Renderer* renderer;

    // Pixels to show in current frame
    std::vector<vec2> pixels;

public:
    Screen(int width, int height);

    // Handle input
    SDL_EventType input();

    // Clear all, set background
    void putBackground(uint8_t r = 0, uint8_t g = 0, uint8_t b = 0, uint8_t opacity = 255);

    // Append pixel for drawing in the frame
    void putPixel(double x, double y, 
                    uint8_t r = 255, uint8_t g = 255, 
                    uint8_t b = 255, uint8_t opacity = 255);

    // Draw line from one point to another
    void putLine(double x1, double y1, double x2, double y2,
                    uint8_t r = 255, uint8_t g = 255, 
                    uint8_t b = 255, uint8_t opacity = 255);

    // Draw figure
    void putFigure(Shape3D& figure,
                    uint8_t r = 255, uint8_t g = 255, 
                    uint8_t b = 255, uint8_t opacity = 255);

    // Show frame
    void show();

    // Clear pixels
    void clear();

    ~Screen();
};