#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_scancode.h>
#include <SDL2/SDL_video.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <stdexcept>


class Screen {
    SDL_Window* window;
    SDL_Renderer* renderer;

public:
    Screen(int width, int height) {
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
    SDL_EventType input() {
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


    void show() {
        // Output
        // Black background
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Show
        SDL_RenderPresent(renderer);
    }


    ~Screen() {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);

        SDL_Quit();
    }
};

constexpr int g_width = 800;
constexpr int g_height = 800;


int main() {
    Screen screen(g_width, g_height);

    // Main application loop
    while (true) {
        screen.show();

        if (screen.input() == SDL_QUIT)
            break;

        SDL_Delay(10);
    }

    return 0;
}