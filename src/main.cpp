#include <SDL2/SDL.h>
#include <iostream>
#include "renderer.h"
#include "menu.h"

int main(int argc, char* argv[]) {
    // SDL initialization
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << "\n";
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("FusionPlay", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << "\n";
        return 1;
    }

    Renderer renderer(window);
    Menu menu(renderer.getSDLRenderer()); // Pass the SDL_Renderer to the menu
    menu.addItem("Start Game");
    menu.addItem("Settings");
    menu.addItem("Exit");

    // Main loop
    bool quit = false;
    SDL_Event event;

    while (!quit) {
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            menu.handleInput(event); // Handle menu input
        }

        // Clear the renderer
        renderer.clear();

        // Render menu
        menu.render();

        // Present the renderer
        renderer.present();
    }

    // Cleanup
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
