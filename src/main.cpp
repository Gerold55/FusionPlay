#include <iostream>
#include <lua.hpp>
#include <SDL.h>
#include <GL/glew.h>

// Function declarations
void initSDL();
void initOpenGL();
void runLuaScript(lua_State* L);
void cleanup();

SDL_Window* window;
SDL_GLContext glContext;

int main(int argc, char** argv) {
    initSDL();
    initOpenGL();

    lua_State* L = luaL_newstate();
    luaL_openlibs(L); // Open standard libraries

    // Run the Lua script to draw the cube
    runLuaScript(L);

    // Main rendering loop
    bool running = true;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Call the drawCube function from the Lua script
        lua_getglobal(L, "drawCube");
        if (lua_pcall(L, 0, 0, 0) != LUA_OK) {
            std::cerr << "Lua error: " << lua_tostring(L, -1) << std::endl;
            lua_pop(L, 1); // Pop the error message
        }

        // Swap buffers
        SDL_GL_SwapWindow(window);
    }

    lua_close(L);
    cleanup();
    return 0;
}

void initSDL() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        exit(1);
    }

    window = SDL_CreateWindow("FusionPlay Cube", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);
    if (!window) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        exit(1);
    }

    glContext = SDL_GL_CreateContext(window);
}

void initOpenGL() {
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW!" << std::endl;
        exit(1);
    }

    glEnable(GL_DEPTH_TEST); // Enable depth testing
    glViewport(0, 0, 800, 600);
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f); // Set clear color
}

void runLuaScript(lua_State* L) {
    if (luaL_dofile(L, "cube.lua") != LUA_OK) {
        std::cerr << "Failed to load Lua script: " << lua_tostring(L, -1) << std::endl;
        lua_pop(L, 1);
    }
}

void cleanup() {
    SDL_GL_DeleteContext(glContext);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
