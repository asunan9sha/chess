#ifndef CHESS_MASTERRENDERER_HPP
#define CHESS_MASTERRENDERER_HPP


#include "sfmlrenderer.hpp"

class MasterRenderer {
public:
    void submit(const sf::Drawable &drawable);
    void flush();

private:
    SfmlRenderer sfmlRenderer_;
};


#endif
