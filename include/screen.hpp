#pragma once

// C++ standard libraries
#include <stdexcept>


// SDL libraries
#include <SDL2/SDL.h>

class Screen {
    SDL_Window* window;
    SDL_Renderer* renderer;

public:
    Screen(int width, int height);

    // Handle input
    SDL_EventType input();

    void show();

    ~Screen();
};