#include "screen.hpp"
#include "shape3d.hpp"
#include <SDL_render.h>
#include <numeric>


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


void Screen::putBackground(uint8_t r, uint8_t g, uint8_t b, uint8_t opacity) {
    // Color for background
    SDL_SetRenderDrawColor(renderer, r, g, b, opacity);

    // Render background
    SDL_RenderClear(renderer);
}


void Screen::putPixel(double x, double y, uint8_t r, uint8_t g, uint8_t b, uint8_t opacity) {
    pixels.push_back(vec2{x, y, r, g, b, opacity});
}


void Screen::putLine(double x1, double y1, double x2, double y2,
                        uint8_t r, uint8_t g, uint8_t b, uint8_t opacity) {
    // Set color
    SDL_SetRenderDrawColor(renderer, r, g, b, opacity);

    // SDL function for drawing lines, performs less accurately
    // SDL_RenderDrawLineF(renderer, x1, y1, x2, y2);

    // Get legs of right triangle
    double x = x2 - x1;
    double y = y2 - y1;

    // Get hypotenuse
    double length = std::sqrt(x*x + y*y);
    // To avoid division by 0
    double angle = std::atan2(y, x);

    // For each pixel of hypotenuse,
    // calculate (x,y) coordinates
    for (double i = 0.0; i < length; i++) {
        SDL_RenderDrawPointF(renderer, x1 + cos(angle) * i, y1 + sin(angle) * i);
    }
}


void Screen::putFigure(Shape3D& figure, uint8_t r, uint8_t g, uint8_t b, uint8_t opacity) {
    // White color for figures
    SDL_SetRenderDrawColor(renderer, r, g, b, opacity);

    // Put vertices
    const auto& vertices = figure.getVertices();

    for (const vec3& vertex : vertices) {
        SDL_RenderDrawPointF(renderer, vertex.x, vertex.y);
    }

    // Put connections
    const auto& connections = figure.getConnections();

    for (const std::pair<int, int> conn : connections) {
        putLine(
            vertices[conn.first].x,
            vertices[conn.first].y,
            vertices[conn.second].x,
            vertices[conn.second].y,
            r, g, b, opacity
        );
    }
}


void Screen::show() {
    // Color and show pixels
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    for (auto& el : pixels) {
        SDL_RenderDrawPointF(renderer, el.x, el.y);
    }

    // Show
    SDL_RenderPresent(renderer);
}


void Screen::clear() {
    pixels.clear();
}


Screen::~Screen() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
}