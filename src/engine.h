#ifndef ENGINE_H
#define ENGINE_H

class Engine {
public:
    bool initialize();
    void update();
    void render();
    void shutdown();
};

#endif // ENGINE_H
