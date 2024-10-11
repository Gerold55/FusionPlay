#ifndef RENDERER_H
#define RENDERER_H

#include <SDL.h>

class Renderer {
public:
    void drawCube(SDL_Renderer* renderer, float rotationAngle);
};

#endif // RENDERER_H
