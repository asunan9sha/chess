#include "king.hpp"

King::King(PieceType type)
    : Piece(type, type == PieceType::whiteKing ? sf::IntRect(0, 0, 200, 200) : sf::IntRect(0, 200, 200, 200)) {
  isWhite_ = type == PieceType::whiteKing;
}

std::vector<vec2> &King::getPossibleMoves() {
  possibleMoves_.clear();

  const float spacing = 100.0f;

  float x = getPosition().x;
  float y = getPosition().y;

  //positions from top left corner
  if (x + spacing <= 700) {
    possibleMoves_.emplace_back(x + spacing, y);
  }
  if (x - spacing >= 0) {
    possibleMoves_.emplace_back(x - spacing, y);
  }
  if (x - spacing >= 0 && y - spacing >= 0) {
    possibleMoves_.emplace_back(x - spacing, y - spacing);
  }
  if (x + spacing <= 700 && y + spacing <= 700) {
    possibleMoves_.emplace_back(x + spacing, y + spacing);
  }
  if (y + spacing <= 700) {
    possibleMoves_.emplace_back(x, y + spacing);
  }
  if (y - spacing >= 0 ) {
    possibleMoves_.emplace_back(x, y - spacing);
  }
  if (x - spacing >= 0 && y + spacing <= 700) {
    possibleMoves_.emplace_back(x - spacing, y + spacing);
  }
  if (x + spacing <= 700 && y - spacing >= 0) {
    possibleMoves_.emplace_back(x + spacing, y - spacing);
  }
  return possibleMoves_;
}
