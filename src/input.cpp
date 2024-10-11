// Input.cpp
#include "Input.h"

Input::Input() {}

Input::~Input() {}

void Input::handleInput() {
    while (SDL_PollEvent(&event)) {
        // Handle input events (keyboard, controller, etc.)
        if (event.type == SDL_QUIT) {
            // Handle quit
        }
    }
}
