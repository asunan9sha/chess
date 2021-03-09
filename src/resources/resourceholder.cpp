#include "resourceholder.hpp"

ResourceHolder::ResourceHolder() :
        textures_("res/textures/"), fonts_("res/fonts/"){}

ResourceHolder &ResourceHolder::get() {
    static ResourceHolder res;
    return res;
}

const sf::Texture &ResourceHolder::getTexture(const std::string &name, bool isFullPath) {
    return get().textures_.get(name, isFullPath);
}
const sf::Font &ResourceHolder::getFont(const std::string &name, bool isFullPath) {
    return get().fonts_.get(name, isFullPath);
}
//const sf::SoundBuffer &ResourceHolder::getSoundBuffer(const std::string &name, bool isFullPath) {
//	return get().soundBuffers_.get(name, isFullPath);;
//}
