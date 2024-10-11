#include "lua_manager.h"
#include <iostream>

LuaManager::LuaManager() {
    L = luaL_newstate();
    luaL_openlibs(L);
}

LuaManager::~LuaManager() {
    lua_close(L);
}

void LuaManager::initialize() {
    registerFunctions(); // Register functions before executing scripts
}

void LuaManager::executeScript(const char* scriptPath) {
    if (luaL_dofile(L, scriptPath) != LUA_OK) {
        std::cerr << "Error executing Lua script: " << lua_tostring(L, -1) << std::endl;
        lua_pop(L, 1); // Pop the error message
    }
}

// Function to render the cube using OpenGL
void LuaManager::renderCube() {
    // Your existing OpenGL cube rendering logic here
    GLfloat vertices[] = {
        -0.5f, -0.5f, -0.5f,  0.5f, -0.5f, -0.5f,  0.5f,  0.5f, -0.5f,
         0.5f,  0.5f, -0.5f, -0.5f,  0.5f, -0.5f, -0.5f, -0.5f, -0.5f,
        // Other cube vertices...
    };

    static GLuint VBO, VAO;
    static bool initialized = false;
    if (!initialized) {
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
        initialized = true;
    }

    // Use shader program (assume you have shader program initialized)
    GLuint shaderProgram; // Assume this variable is initialized correctly.
    glUseProgram(shaderProgram);

    // Draw the cube
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);
}

// Function to bind the renderCube to Lua
int lua_renderCube(lua_State* L) {
    LuaManager* luaManager = reinterpret_cast<LuaManager*>(lua_touserdata(L, lua_upvalueindex(1)));
    luaManager->renderCube();
    return 0; // No return value
}

void LuaManager::registerFunctions() {
    lua_pushlightuserdata(L, this); // Push the LuaManager instance to Lua
    lua_pushcclosure(L, lua_renderCube, 1); // Create a closure to bind renderCube
    lua_setglobal(L, "renderCube"); // Register the function globally
}
