#include "font_renderer.h"
#include <SDL.h>
#include <SDL_ttf.h>

FontRenderer::FontRenderer(const std::string& fontPath, int fontSize, SDL_Renderer* renderer) {
    // Initialize TTF
    if (TTF_Init() == -1) {
        SDL_Log("TTF_Init: %s\n", TTF_GetError());
        return;
    }

    // Load the font
    font = TTF_OpenFont(fontPath.c_str(), fontSize);
    if (!font) {
        SDL_Log("Failed to load font: %s\n", TTF_GetError());
    }
}

FontRenderer::~FontRenderer() {
    TTF_CloseFont(font);
    TTF_Quit();
}

void FontRenderer::renderText(SDL_Renderer* renderer, const std::string& text, int x, int y) {
    SDL_Color color = {255, 255, 255}; // White color for the text
    SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);
    if (!surface) {
        SDL_Log("TTF_RenderText_Solid: %s\n", TTF_GetError());
        return;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect dstRect = {x, y, surface->w, surface->h};
    SDL_RenderCopy(renderer, texture, nullptr, &dstRect);

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}
