#include "renderer.h"
#include <SDL.h>

// Implement your renderer methods here
void Renderer::drawCube(SDL_Renderer* renderer, float rotationAngle) {
    // Draw a placeholder cube (2D representation)
    int x = 400; // Center x
    int y = 300; // Center y
    int size = 50; // Size of the cube

    SDL_Rect cubeRect = { x - size / 2, y - size / 2, size, size };
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red color
    SDL_RenderFillRect(renderer, &cubeRect);
}
