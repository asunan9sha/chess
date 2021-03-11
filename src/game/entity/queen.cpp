#include "queen.hpp"

Queen::Queen(PieceType type, const vec2 &pos, const vec2 &size, const sf::Texture &texture)
    : Piece(type, pos, size, texture) {

  if(Queen::getType() == PieceType::whiteQueen){
    setTextureRect(sf::IntRect(200, 0, 200, 200));
  } else {
    setTextureRect(sf::IntRect(200, 200, 200, 200));
  }
}