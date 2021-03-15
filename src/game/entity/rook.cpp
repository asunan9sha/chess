#include "rook.hpp"
#include "board.hpp"

Rook::Rook(PieceType type)
    : Piece(type, type == PieceType::whiteRook ? sf::IntRect(800, 0, 200, 200) : sf::IntRect(800, 200, 200, 200)) {

}

std::vector<vec2i> &Rook::getPossibleMoves(vec2i currentPos) {
  return possibleMoves_;
}
