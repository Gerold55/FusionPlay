// Graphics.h
#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL.h>
#include <string>

class Graphics {
public:
    Graphics(SDL_Renderer* renderer);
    ~Graphics();
    
    SDL_Texture* loadTexture(const std::string& filePath);
    void draw(SDL_Texture* texture, int x, int y, int width, int height);
    
private:
    SDL_Renderer* renderer;
};

#endif // GRAPHICS_H
