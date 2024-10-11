// graphics.cpp
#include "graphics.h"

Graphics::Graphics(SDL_Renderer* renderer) : mRenderer(renderer) {}

void Graphics::clear() {
    SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 255); // Set to black
    SDL_RenderClear(mRenderer);
}

void Graphics::present() {
    SDL_RenderPresent(mRenderer);
}

void Graphics::drawCube(float x, float y, float z, float size) {
    // Placeholder for drawing a 3D cube; implement the actual rendering logic here.
    // For now, we can just draw a simple rectangle to represent the cube
    SDL_Rect rect = { static_cast<int>(x), static_cast<int>(y), static_cast<int>(size), static_cast<int>(size) };
    SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255); // Set to white
    SDL_RenderFillRect(mRenderer, &rect);
}
