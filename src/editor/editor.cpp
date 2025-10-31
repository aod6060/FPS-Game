#include "editor.hpp"

namespace editor {
    void init() {

    }

    void handleEvent(SDL_Event* e) {

    }

    void update(float delta) {

    }

    void render() {
        render::clear(glm::vec4(glm::vec3(100.0f, 149.0f, 237.0f) / 255.0f, 1.0f));
    }

    void release() {

    }

    void setup(app::Config* config) {
        config->caption = "FPS Game: Editor";
        config->width = 1280;
        config->height = 720;
        config->initCB = init;
        config->handleEventCB = handleEvent;
        config->updateCB = update;
        config->renderCB = render;
        config->releaseCB = release;
    }

}