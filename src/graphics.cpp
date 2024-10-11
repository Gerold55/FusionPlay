// Graphics.cpp
#include "Graphics.h"
#include <iostream>

Graphics::Graphics(SDL_Renderer* renderer) : renderer(renderer) {}

Graphics::~Graphics() {}

SDL_Texture* Graphics::loadTexture(const std::string& filePath) {
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP(filePath.c_str()));
    if (!texture) {
        std::cerr << "Failed to load texture: " << filePath << " SDL_Error: " << SDL_GetError() << std::endl;
    }
    return texture;
}

void Graphics::draw(SDL_Texture* texture, int x, int y, int width, int height) {
    SDL_Rect dstrect = { x, y, width, height };
    SDL_RenderCopy(renderer, texture, nullptr, &dstrect);
}
