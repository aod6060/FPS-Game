#include "editor/editor.hpp"
#include "game/game.hpp"

int main(int argc, char** argv) {
    /*
    app::Config config;

    game::setup(&config);
    
    app::init(&config);
    app::update();
    app::release();
    */

    app::Config config;

    if(argc > 1) {
        if(std::string(argv[1]) == "editor") {
            editor::setup(&config);
        } else {
            game::setup(&config);
        }
    } else {
        game::setup(&config);
    }

    app::init(&config);
    app::update();
    app::release();

    return 0;
}
