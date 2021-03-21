#include <resources/resourceholder.hpp>
#include "piece.hpp"
#include "renderers/masterrenderer.hpp"
#include "board.hpp"


Piece::Piece(PieceType type, const sf::IntRect &rect)
    : pieceType_(type), isMoved_(false), isOnTop_(false) {
  setSize({Board::CELL_SIZE, Board::CELL_SIZE});
  setTexture(&ResourceHolder::getTexture(ATLAS));
  setTextureRect(rect);
}

void Piece::render(MasterRenderer &renderer) {
  renderer.submit(*this);
}

void Piece::copy(const Piece &other) {
  *this = other;
}