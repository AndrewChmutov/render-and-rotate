#include "screen.hpp"


Screen::Screen(int width, int height) {
    // Initialize video subsystem
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        throw std::runtime_error("Video initialization failed");

    // Setup window and renderer
    SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_OPENGL, &window, &renderer);
    SDL_SetWindowTitle(window, "Sample render");

    // Make output bigger
    SDL_RenderSetScale(renderer, 2, 2);
}


// Handle input
SDL_EventType Screen::input() {
    SDL_Event event;

    // Handle events
    while (SDL_PollEvent(&event)) {
        // Close window button or ESC key
        if (event.type == SDL_QUIT ||
            (event.type == SDL_KEYDOWN && event.key.keysym.scancode == SDL_SCANCODE_ESCAPE))
            return SDL_QUIT;
    }

    // Default case
    return SDL_USEREVENT;
}


void Screen::show() {
    // Output
    // Black background
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Show
    SDL_RenderPresent(renderer);
}


Screen::~Screen() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
}