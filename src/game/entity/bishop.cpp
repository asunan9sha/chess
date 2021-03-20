#include "bishop.hpp"

Bishop::Bishop(PieceType type)
    : Piece(type, type == PieceType::whiteBishop ? sf::IntRect(400, 0, 200, 200) : sf::IntRect(400, 200, 200, 200)) {
  isWhite_ = type == PieceType::whiteBishop;
}

std::vector<vec2> &Bishop::getPossibleMoves() {
  const float spacing = 100.0f;

  float tempX = getPosition().x;
  float tempY = getPosition().y;
  while (tempX + spacing <= 700 && tempY + spacing <= 700) {
    tempX += spacing;
    tempY += spacing;
    possibleMoves_.emplace_back(tempX, tempY);
  }
  tempX = getPosition().x;
  tempY = getPosition().y;

  while (tempX - spacing >= 0 && tempY - spacing >= 0) {
    tempX -= spacing;
    tempY -= spacing;
    possibleMoves_.emplace_back(tempX, tempY);
  }
  tempX = getPosition().x;
  tempY = getPosition().y;

  while (tempX + spacing <= 700 && tempY - spacing >= 0) {
    tempX += spacing;
    tempY -= spacing;
    possibleMoves_.emplace_back(tempX, tempY);
  }
  tempX = getPosition().x;
  tempY = getPosition().y;

  while (tempX - spacing >= 0 && tempY + spacing <= 700) {
    tempX -= spacing;
    tempY += spacing;
    possibleMoves_.emplace_back(tempX, tempY);
  }
  return possibleMoves_;
}

