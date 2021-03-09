#include "sfmlrenderer.hpp"
#include "app/window.hpp"

void SfmlRenderer::submit(const sf::Drawable &drawable) {
    drawables_.push_back(&drawable);
}

void SfmlRenderer::flush() {
    static Window *window = &Window::get();

    for (auto &&d : drawables_) {
        window->draw(*d);
    }

    drawables_.clear();
}
