#include "bishop.hpp"

Bishop::Bishop(PieceType type, const vec2 &pos, const vec2 &size, const sf::Texture &texture)
    : Piece(type, pos, size, texture) {
  if(Bishop::getType() == PieceType::whiteBishop){
    setTextureRect(sf::IntRect(400, 0, 200, 200));
  } else {
    setTextureRect(sf::IntRect(400, 200, 200, 200));
  }
}
void Bishop::move() {

}
