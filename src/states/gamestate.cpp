#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>

#include "renderers/masterrenderer.hpp"
#include "gamestate.hpp"

GameState::GameState(Application *app) :
    BaseState(app) {

  board = new Board({0.0f, 0.0f}, {800.0f, 800.0f}, ResourceHolder::getTexture("board.png"), 0);
//  pieces_.push_back(new Queen({55.0f - 30.0f, 55.0f - 30.0f}, {80.0f, 80.0f}, ResourceHolder::getTexture("ChessPiecesArray.png")));
 // pieces_.push_back(new Pawn({25.0f - 30.0f, 25.0f - 30.0f}, {80.0f, 80.0f}, ResourceHolder::getTexture("ChessPiecesArray.png")));
}

GameState::~GameState() {
}

void GameState::render(MasterRenderer &renderer) {
  renderer.submit(*board);

  for(const auto &p : board->pieces_){
    renderer.submit(*p);
  }
//  for(const auto &p : pieces_){
//    renderer.submit(*p);
//  }
}

void GameState::update(float delta) {
}

void GameState::fixedUpdate(float delta) {
}

void GameState::input(const sf::Event &event) {
}

void GameState::input(float delta) {
}

void GameState::onOpen() {
  printf("gameState On Open \n");
}
