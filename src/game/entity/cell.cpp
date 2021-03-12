#include "cell.hpp"
#include "board.hpp"
#include "renderers/masterrenderer.hpp"

Cell::Cell(std::unique_ptr<Piece> piece, const vec2 &pos, bool isWhite)
    : isWhite_(isWhite), piece_(std::move(piece)){
  setPosition(pos);
  setSize({Board::CELL_SIZE, Board::CELL_SIZE});
  setFillColor(isWhite ? sf::Color::White : sf::Color::Green);
  if (piece_) {
    piece_->setPosition(pos);
    isPiecePlaced_ = true;
  } else {
    isPiecePlaced_ = false;
  }
}

void Cell::render(MasterRenderer &renderer) {
  renderer.submit(*this);
  if (piece_) {
    piece_->render(renderer);
  }
}

bool Cell::getPieceColor() {
  const int pieceType = static_cast<int>(this->getPiece().getType());
  return pieceType <= 6;
}
