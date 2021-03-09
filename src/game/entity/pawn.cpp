#include "pawn.hpp"

Pawn::Pawn(PieceType type, const vec2 &pos, const vec2 &size, const sf::Texture &texture)
    : Piece(type, pos, size, texture) {
  if (Pawn::getType() == PieceType::whitePawn) {
    setTextureRect(sf::IntRect(1000, 0, 200, 200));
  } else {
    setTextureRect(sf::IntRect(1000, 200, 200, 200));
  }

}

void Pawn::move() {

}
void Pawn::moveS(Piece& piece) {

}
