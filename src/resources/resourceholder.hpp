
#ifndef CHESS_RESOURCEHOLDER_HPP
#define CHESS_RESOURCEHOLDER_HPP

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
//#include <SFML/Audio/SoundBuffer.hpp>
#include "resourcemanager.hpp"
#include "utils/singleton.hpp"

class ResourceHolder : public Singleton {
public:
    static ResourceHolder &get();

    static const sf::Texture& getTexture(const std::string& name, bool isFullPath = false);
    static const sf::Font& getFont(const std::string& name, bool isFullPath = false);
    //static const sf::SoundBuffer& getSoundBuffer(const std::string& name, bool isFullPath = false);

private:
    explicit ResourceHolder();

private:
    ResourceManager<sf::Texture> textures_;
    ResourceManager<sf::Font> fonts_;
    //ResourceManager<sf::SoundBuffer> soundBuffers_;
};


#endif
