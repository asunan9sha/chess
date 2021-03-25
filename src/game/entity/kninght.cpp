#include "kninght.hpp"

Knight::Knight(PieceType type)
    : Piece(type, type == PieceType::whiteKnight ? sf::IntRect(600, 0, 200, 200) : sf::IntRect(600, 200, 200, 200)) {
  isWhite_ = type == PieceType::whiteKnight;
}

std::vector<vec2> &Knight::getPossibleMoves() {
  possibleMoves_.clear();

  const float longSpacing = 200.0f;
  const float shortSpacing = 100.0f;

  const float x = getPosition().x;
  const float y = getPosition().y;

  possibleMoves_.emplace_back(x - shortSpacing, y - longSpacing);
  possibleMoves_.emplace_back(x + shortSpacing, y - longSpacing);

  possibleMoves_.emplace_back(x - shortSpacing, y + longSpacing);
  possibleMoves_.emplace_back(x + shortSpacing, y + longSpacing);

  possibleMoves_.emplace_back(x - longSpacing, y + shortSpacing);
  possibleMoves_.emplace_back(x - longSpacing, y - shortSpacing);

  possibleMoves_.emplace_back(x + longSpacing, y + shortSpacing);
  possibleMoves_.emplace_back(x + longSpacing, y - shortSpacing);

  return possibleMoves_;
}
