#include "rook.hpp"
#include "board.hpp"


Rook::Rook(PieceType type)
    : Piece(type, type == PieceType::whiteRook ? sf::IntRect(800, 0, 200, 200) : sf::IntRect(800, 200, 200, 200)){
  isWhite_ = type == PieceType::whiteRook;
}
std::vector<vec2> &Rook::getPossibleMoves() {
  possibleMoves_.clear();

  const float x = getPosition().x;
  const float y = getPosition().y;
  const float spacing = 100.0f;

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