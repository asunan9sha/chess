#include <iostream>
#include "cell.hpp"
#include "board.hpp"
#include "renderers/masterrenderer.hpp"

Cell::Cell(std::shared_ptr<Piece> piece, const vec2 &pos, bool isWhite)
    : isWhite_(isWhite), piece_(std::move(piece)) {
  setPosition(pos);
  setSize({Board::CELL_SIZE, Board::CELL_SIZE});
  originalColor_ = isWhite ? sf::Color::White : sf::Color::Cyan;
  setFillColor(originalColor_);

  if (piece_) {
    piece_->setPosition(pos);
    isWhite_ = isWhite;
  }
}

void Cell::render(MasterRenderer &renderer) {
  renderer.submit(*this);
  if (piece_) {
    piece_->render(renderer);
  }
}

bool Cell::isPeacePlaced() const {
  return (bool)piece_;
}

void Cell::moveTo(Cell &targetCell) {
  if(!piece_){
    return;
  }
  targetCell.piece_ = std::move(piece_);
  targetCell.piece_->setPosition(targetCell.getPosition());
  piece_ = std::shared_ptr<Piece>();
}
