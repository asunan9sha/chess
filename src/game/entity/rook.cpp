#include "rook.hpp"
#include "board.hpp"

Rook::Rook(PieceType type, const vec2 &pos, const vec2 &size, const sf::Texture &texture)
    : Piece(type, pos, size, texture) {

  if (Rook::getType() == PieceType::whiteRook) {
    setTextureRect(sf::IntRect(800, 0, 200, 200));
  } else {
    setTextureRect(sf::IntRect(800, 200, 200, 200));
  }
}

void Rook::showMoves() {
  circleShapes_.clear();

  bool searchingX = true;
  bool searchingY = true;
  while (searchingX) {
    int forwardIndex = 1;
    if (Board::getByIndex((getBoardPos().x + forwardIndex), getBoardPos().y) < 6) {
      circleShapes_.push_back(new sf::CircleShape(50));
      circleShapes_.back()->setPosition(pickedPiece_->getPosition().x, pickedPiece_->getPosition().y);
      circleShapes_.back()->setFillColor(sf::Color(0, 0, 0, 150));
      forwardIndex++;
      continue;
    } else {
      searchingX = false;
    }
  }
}
