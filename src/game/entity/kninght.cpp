#include "kninght.hpp"

Knight::Knight(PieceType type, const vec2 &pos, const vec2 &size, const sf::Texture &texture)
    : Piece(type, pos, size, texture) {

  if (Knight::getType() == PieceType::whiteKnight) {
    setTextureRect(sf::IntRect(600, 0, 200, 200));
  } else {
    setTextureRect(sf::IntRect(600, 200, 200, 200));
  }
}
void Knight::move() {

}
