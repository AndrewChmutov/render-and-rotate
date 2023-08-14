#include <iostream>
#include "screen.hpp"
#include "cube.hpp"
#include "coin.hpp"

constexpr int g_width = 800;
constexpr int g_height = 800;


int main() {
    // Initialize screen and entities to show
    Screen screen(g_width, g_height);
    Cube cube(200, 200, 200, 100);
    Coin coin1(200, 200, 200, 50, 5);
    Coin coin2(200, 200, 200, 50, 5);


    // Main application loop
    while (true) {
        // Background 
        screen.putBackground();

        // Rotation
        cube.rotate(0.01, 0.04, 0.02);
        coin1.rotate(0.03, 0.05, 0.04);
        coin2.rotate(0.04, 0.02, 0.03);

        // Plot on screen
        screen.putFigure(cube);
        screen.putFigure(coin1);
        screen.putFigure(coin2);

        // Show everything
        screen.show();

        // Clear single pixels
        screen.clear();

        // Handle input
        if (screen.input() == SDL_QUIT)
            break;

        SDL_Delay(20);
    }

    return 0;
}