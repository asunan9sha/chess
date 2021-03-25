#include "queen.hpp"

Queen::Queen(PieceType type)
    : Piece(type, type == PieceType::whiteQueen ? sf::IntRect(200, 0, 200, 200) : sf::IntRect(200, 200, 200, 200)) {
  isWhite_ = type == PieceType::whiteQueen;
}
std::vector<vec2> &Queen::getPossibleMoves() {
  possibleMoves_.clear();

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

  const float x = getPosition().x;
  const float y = getPosition().y;

  float tempPos = getPosition().x;
  while (tempPos + spacing <= 700){
    tempPos+= spacing;
    possibleMoves_.emplace_back(tempPos, y);
  }
  tempPos = getPosition().x;

  while (tempPos - spacing >= 0){
    tempPos-= spacing;
    possibleMoves_.emplace_back(tempPos, y);
  }
  tempPos = getPosition().y;

  while (tempPos + spacing <= 700){
    tempPos+= spacing;
    possibleMoves_.emplace_back(x, tempPos);
  }
  tempPos = getPosition().y;

  while (tempPos - spacing >= 0){
    tempPos-= spacing;
    possibleMoves_.emplace_back(x, tempPos);
  }
  return possibleMoves_;
}