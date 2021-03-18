#include "pawn.hpp"

Pawn::Pawn(PieceType type)
    : Piece(type, type == PieceType::whitePawn ? sf::IntRect(1000, 0, 200, 200) : sf::IntRect(1000, 200, 200, 200)) {
  isWhite_ = type == PieceType::whitePawn;
}

std::vector<vec2> &Pawn::getPossibleMoves() {
  if(getPosition().y == 0){
    return possibleMoves_;
  }

  int spacing = isOnTop_ ? 100.0f : -100.0f;

  if (isMoved_) {
    possibleMoves_.push_back(vec2({getPosition().x, getPosition().y + spacing}));
    if (getPosition().x + 100.0f <= 700) {
      possibleMoves_.push_back(vec2({getPosition().x + 100.0f, getPosition().y + spacing}));
    }
    if (getPosition().x - 100.0f >= 0) {
      possibleMoves_.push_back(vec2({getPosition().x - 100.0f, getPosition().y + spacing}));
    }
  } else {
    possibleMoves_.push_back(vec2({getPosition().x, getPosition().y + spacing}));
    possibleMoves_.push_back(vec2({getPosition().x, possibleMoves_.back().y + spacing}));
    if (getPosition().x + 100.0f <= 700) {
      possibleMoves_.push_back(vec2({getPosition().x + 100.0f, getPosition().y + spacing}));
    }
    if (getPosition().x - 100.0f >= 0) {
      possibleMoves_.push_back(vec2({getPosition().x - 100.0f, getPosition().y + spacing}));
    }
  }
  return possibleMoves_;
}
