#ifndef FONT_RENDERER_H
#define FONT_RENDERER_H

#include <string>
#include <SDL.h>
#include <SDL_ttf.h>

class FontRenderer {
public:
    FontRenderer(const std::string& fontPath, int fontSize, SDL_Renderer* renderer);
    ~FontRenderer();

    void renderText(SDL_Renderer* renderer, const std::string& text, int x, int y);

private:
    TTF_Font* font;
};

#endif // FONT_RENDERER_H
