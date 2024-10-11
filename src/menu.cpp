#include "menu.h"
#include <SDL2/SDL_ttf.h>

Menu::Menu(SDL_Renderer* renderer)
    : mRenderer(renderer), mSelectedItem(0), mItemWidth(200), mItemHeight(50) {
}

void Menu::addItem(const std::string& item) {
    mItems.push_back(item);
}

void Menu::render() {
    for (size_t i = 0; i < mItems.size(); ++i) {
        SDL_Rect itemRect = { 100, static_cast<int>(250 + (i * (mItemHeight + 20))), mItemWidth, mItemHeight };
        SDL_SetRenderDrawColor(mRenderer, (mSelectedItem == i) ? 0 : 255, (mSelectedItem == i) ? 255 : 0, 0, 255);
        SDL_RenderFillRect(mRenderer, &itemRect);
        // TODO: Render text for mItems[i]
    }
}

void Menu::handleInput(const SDL_Event& event) {
    if (event.type == SDL_KEYDOWN) {
        if (event.key.keysym.sym == SDLK_UP) {
            mSelectedItem = (mSelectedItem - 1 + mItems.size()) % mItems.size();
        } else if (event.key.keysym.sym == SDLK_DOWN) {
            mSelectedItem = (mSelectedItem + 1) % mItems.size();
        }
    }
}

int Menu::getSelectedItem() const {
    return mSelectedItem;
}
