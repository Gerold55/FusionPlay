// Input.h
#ifndef INPUT_H
#define INPUT_H

#include <SDL.h>

class Input {
public:
    Input();
    ~Input();
    
    void handleInput();
    
private:
    SDL_Event event;
};

#endif // INPUT_H
