#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <iostream>
#include <SDL2/SDL.h>

int main() {
    // For visual output
    SDL_Window* window;
    SDL_Renderer* renderer;

    // Setup window and renderer
    SDL_CreateWindowAndRenderer(800, 800, SDL_WINDOW_OPENGL, &window, &renderer);
    SDL_SetWindowTitle(window, "Sample render");

    // Make output bigger
    SDL_RenderSetScale(renderer, 2, 2);

    // Main application loop
    bool isRunning = true;
    while (isRunning) {
        SDL_Event event;

        // Handle events
        while (SDL_PollEvent(&event)) {
            // Close window button
            if (event.type == SDL_QUIT)
                isRunning = false;
        }

        // Output
        // Black background
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Show
        SDL_RenderPresent(renderer);
    }


    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}