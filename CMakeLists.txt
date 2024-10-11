cmake_minimum_required(VERSION 3.10)
project(FusionPlay)

# Find the SDL2 package
find_package(SDL2 REQUIRED)
find_package(Lua REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${LUA_INCLUDE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Add source files
set(SOURCES
    src/main.cpp
    src/renderer.cpp
    src/menu.cpp
    # Add other source files here
)

# Create the executable
add_executable(FusionPlay ${SOURCES})

# Link libraries
target_link_libraries(FusionPlay ${SDL2_LIBRARIES} ${LUA_LIBRARIES})
