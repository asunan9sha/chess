#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>

#include "renderers/masterrenderer.hpp"
#include "gamestate.hpp"

GameState::GameState(Application *app) :
    BaseState(app) {

  board_ = new Board({0.0f, 0.0f}, {800.0f, 800.0f}, ResourceHolder::getTexture("board.png"), 0);
}

GameState::~GameState() {
}

void GameState::render(MasterRenderer &renderer) {
  renderer.submit(*board_);

  for (const auto &p : board_->pieces_) {
    renderer.submit(*p);
  }
  auto picked = Piece::getPickedPiece();
  if(picked){
    std::cout<<"picked piece = "<<static_cast<int>(picked->getType())<<std::endl;
    for(const auto &c: picked->getCircles()){
      renderer.submit(*c);
    }
  }
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
