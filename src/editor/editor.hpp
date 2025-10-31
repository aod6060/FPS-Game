#ifndef EDITOR_HPP
#define EDITOR_HPP

#include "../game/game.hpp"


namespace editor {
    void init();
    void handleEvent(SDL_Event* e);
    void update(float delta);
    void render();
    void release();

    void setup(app::Config* config);
}

#endif