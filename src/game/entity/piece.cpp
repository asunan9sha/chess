#include <resources/resourceholder.hpp>
#include "piece.hpp"
#include "renderers/masterrenderer.hpp"
#include "board.hpp"
#include "iostream"


Piece::Piece(PieceType type, const sf::IntRect &rect)
    : pieceType_(type), isMoved_(false), isPicked_(false) {
  setSize({Board::CELL_SIZE, Board::CELL_SIZE});
  setTexture(&ResourceHolder::getTexture(ATLAS));
  setTextureRect(rect);
}

void Piece::render(MasterRenderer &renderer) {
  renderer.submit(*this);
}

void Piece::pick() {
  isPicked_ = true;
}

void Piece::unpick() {
  isPicked_ = false;
}

void Piece::copy(const Piece &other) {
  *this = other;
}