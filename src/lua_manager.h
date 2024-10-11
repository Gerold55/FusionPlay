// lua_manager.h
#ifndef LUA_MANAGER_H
#define LUA_MANAGER_H

#include <lua.hpp>
#include <string>

class LuaManager {
public:
    LuaManager();
    ~LuaManager();

    bool loadScript(const std::string& scriptPath);
    void executeScript();

private:
    lua_State* L;
};

#endif // LUA_MANAGER_H
