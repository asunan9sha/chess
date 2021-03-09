#ifndef CHESS_SFMLRENDERER_HPP
#define CHESS_SFMLRENDERER_HPP

#include <vector>

namespace sf {
    class Drawable;
}

class SfmlRenderer {
public:
    void submit(const sf::Drawable &drawable);
    void flush();

private:
    std::vector<const sf::Drawable*> drawables_;
};


#endif
