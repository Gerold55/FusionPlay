#ifndef LUA_MANAGER_H
#define LUA_MANAGER_H

#include <lua.hpp>
#include <GL/glew.h>

class LuaManager {
public:
    LuaManager();
    ~LuaManager();

    void initialize();
    void executeScript(const char* scriptPath);
    void registerFunctions();
    void renderCube();

    // Public getter for lua_State
    lua_State* getLuaState() { return L; }

private:
    lua_State* L;
};

#endif // LUA_MANAGER_H
