#include "piece.hpp"
#include "renderers/masterrenderer.hpp"

Piece::Piece(PieceType type, const vec2 &pos, const vec2 &size, const sf::Texture &texture, float angle) :
    pieceType_(type), isPicked_(false) {

  setOrigin(size.x / 2, size.y / 2);
  setPosition(pos.x, pos.y);
  setRotation(angle);
  setSize(size);
  setTexture(&texture);
}

void Piece::render(MasterRenderer &renderer) {
  renderer.submit(*this);
}
void Piece::pick() {
  isPicked_ = true;
}
void Piece::unPick() {
  isPicked_ = false;
}
