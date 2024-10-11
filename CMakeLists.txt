cmake_minimum_required(VERSION 3.10)
project(FusionPlay)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenGL REQUIRED)
find_package(SDL2 REQUIRED)
find_package(GLEW REQUIRED)

# Find the Lua library
find_package(Lua REQUIRED)
include_directories(${LUA_INCLUDE_DIR})

include_directories(${SDL2_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS} ${LUA_INCLUDE_DIR})

add_executable(FusionPlay src/main.cpp src/lua_manager.cpp)

# Link against the required libraries
target_link_libraries(FusionPlay ${SDL2_LIBRARIES} ${GLEW_LIBRARIES} OpenGL::GL ${LUA_LIBRARIES})
