#include "renderer.h"
#include <iostream>

Renderer::Renderer(SDL_Window* window) {
    mRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!mRenderer) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << "\n";
    }
}

Renderer::~Renderer() {
    SDL_DestroyRenderer(mRenderer);
}

void Renderer::clear() {
    SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 255);
    SDL_RenderClear(mRenderer);
}

void Renderer::present() {
    SDL_RenderPresent(mRenderer);
}

void Renderer::drawCube(float x, float y, float z) {
    SDL_Rect rect = { static_cast<int>(x), static_cast<int>(y), 50, 50 };
    SDL_SetRenderDrawColor(mRenderer, 255, 0, 0, 255);
    SDL_RenderFillRect(mRenderer, &rect);
}

void Renderer::executeLuaScript(const char* scriptPath) {
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);
    if (luaL_dofile(L, scriptPath) != LUA_OK) {
        std::cerr << "Error loading Lua script: " << lua_tostring(L, -1) << "\n";
        lua_pop(L, 1);
    }
    lua_close(L);
}
