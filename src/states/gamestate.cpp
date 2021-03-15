#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>

#include "renderers/masterrenderer.hpp"
#include "gamestate.hpp"

GameState::GameState(Application *app) :
    BaseState(app) {

  board_ = std::make_unique<Board>();
}

void GameState::render(MasterRenderer &renderer) {
  board_->render(renderer);
}

void GameState::update(float delta) {
  board_->update(delta);
}

void GameState::fixedUpdate(float delta) {
}

void GameState::input(const sf::Event &event) {
  board_->input(event);
}

void GameState::input(float delta) {
}

void GameState::onOpen() {
  printf("gameState On Open \n");
}
