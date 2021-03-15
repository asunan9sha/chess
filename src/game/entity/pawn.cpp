#include "pawn.hpp"

Pawn::Pawn(PieceType type)
    : Piece(type, type == PieceType::whitePawn ? sf::IntRect(1000, 0, 200, 200) : sf::IntRect(1000, 200, 200, 200)) {
}

std::vector<vec2i> &Pawn::getPossibleMoves(vec2i currentPos) {
  static bool isOnTop = currentPos.y < 2;
  int spacing = isOnTop ? 1 : -1;
  if (isMoved_) {
    possibleMoves_.push_back(vec2i({currentPos.x, currentPos.y + spacing}));
  } else {
    possibleMoves_.push_back(vec2i({currentPos.x, currentPos.y + spacing}));
    possibleMoves_.push_back(vec2i({currentPos.x, possibleMoves_.back().y + spacing}));
  }
  return possibleMoves_;
}
