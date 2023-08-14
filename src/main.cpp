#include <iostream>
#include "screen.hpp"

constexpr int g_width = 800;
constexpr int g_height = 800;


int main() {
    Screen screen(g_width, g_height);

    for (int i = 0; i < 100; i++) {
        screen.putPixel(100.0 + i, 100);
    }

    // Main application loop
    while (true) {
        screen.show();

        if (screen.input() == SDL_QUIT)
            break;

        SDL_Delay(10);
    }

    return 0;
}