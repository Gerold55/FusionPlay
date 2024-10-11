#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>
#include <lua.hpp>

class Renderer {
public:
    Renderer(SDL_Window* window);
    ~Renderer();

    void clear();
    void present();
    void drawCube(float x, float y, float z);
    void executeLuaScript(const char* scriptPath);
    
    SDL_Renderer* getSDLRenderer() { return mRenderer; }  // Getter for SDL_Renderer

private:
    SDL_Renderer* mRenderer;
};

#endif // RENDERER_H
