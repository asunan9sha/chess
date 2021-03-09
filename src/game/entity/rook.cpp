#include "rook.hpp"

Rook::Rook(PieceType type, const vec2 &pos, const vec2 &size, const sf::Texture &texture)
    : Piece(type, pos, size, texture) {

  if(Rook::getType() == PieceType::whiteRook){
    setTextureRect(sf::IntRect(800, 0, 200, 200));
  } else {
    setTextureRect(sf::IntRect(800, 200, 200, 200));
  }

}
void Rook::move() {

}
