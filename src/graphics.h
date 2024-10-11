// graphics.h
#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL.h>
#include <string>

class Graphics {
public:
    Graphics(SDL_Renderer* renderer);
    void clear();
    void present();
    void drawCube(float x, float y, float z, float size);
    // Add more drawing functions as needed

private:
    SDL_Renderer* mRenderer;
};

#endif // GRAPHICS_H
