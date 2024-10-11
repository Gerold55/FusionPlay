#include <lua.hpp>
#include <iostream>

class LuaManager {
public:
    LuaManager() {
        L = luaL_newstate();
        luaL_openlibs(L);
    }

    ~LuaManager() {
        lua_close(L);
    }

    void loadScript(const std::string& script) {
        if (luaL_dofile(L, script.c_str()) != LUA_OK) {
            std::cerr << "Error loading script: " << lua_tostring(L, -1) << std::endl;
            lua_pop(L, 1);  // Remove error message
        }
    }

    void callUpdate() {
        lua_getglobal(L, "update");
        if (lua_pcall(L, 0, 0, 0) != LUA_OK) {
            std::cerr << "Error calling update: " << lua_tostring(L, -1) << std::endl;
            lua_pop(L, 1);  // Remove error message
        }
    }

private:
    lua_State* L;
};

// In your main loop, you would do something like this
LuaManager luaManager;
luaManager.loadScript("games/Game1/cube.lua");

// Inside your main game loop
while (running) {
    // Handle events...

    luaManager.callUpdate(); // Call the update function from the Lua script

    // Swap buffers...
}
