#ifndef GAME_HPP
#define GAME_HPP

#include "../engine/sys.hpp"

namespace game {
    void init();
    void handleEvent(SDL_Event* e);
    void update(float delta);
    void render();
    void release();

    void setup(app::Config* config);
}

#endif