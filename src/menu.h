#ifndef MENU_H
#define MENU_H

#include <SDL2/SDL.h>
#include <vector>
#include <string>

class Menu {
public:
    Menu(SDL_Renderer* renderer);
    void addItem(const std::string& item);
    void render();
    void handleInput(const SDL_Event& event);
    int getSelectedItem() const;

private:
    SDL_Renderer* mRenderer;
    std::vector<std::string> mItems;
    int mSelectedItem;
    int mItemWidth;
    int mItemHeight;
};

#endif // MENU_H
