#include "king.hpp"

King::King(PieceType type, const vec2 &pos, const vec2 &size, const sf::Texture &texture)
    : Piece(type, pos, size, texture) {

  if(King::getType() == PieceType::whiteKing){
    setTextureRect(sf::IntRect(0, 0, 200, 200));
  } else {
    setTextureRect(sf::IntRect(0, 200, 200, 200));
  }
}
void King::move() {

}
