#include <iostream>
#include "screen.hpp"
#include "cube.hpp"
#include "coin.hpp"

constexpr int g_width = 800;
constexpr int g_height = 800;


int main() {
    Screen screen(g_width, g_height);
    Cube cube(200, 200, 200, 100);
    Coin coin1(200, 200, 200, 50, 5);
    Coin coin2(200, 200, 200, 50, 5);

    for (int i = 0; i < 100; i++) {
        screen.putPixel(100.0 + i, 100);
    }

    // Main application loop
    while (true) {
        screen.putBackground();
        cube.rotate(0.01, 0.04, 0.02);
        coin1.rotate(0.03, 0.05, 0.04);
        coin2.rotate(0.04, 0.02, 0.03);
        screen.putFigure(cube);
        screen.putFigure(coin1);
        screen.putFigure(coin2);
        screen.show();
        screen.clear();

        if (screen.input() == SDL_QUIT)
            break;

        SDL_Delay(20);
    }

    return 0;
}