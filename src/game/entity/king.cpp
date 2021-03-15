#include "king.hpp"

King::King(PieceType type)
  : Piece(type, type == PieceType::whiteKing? sf::IntRect(0, 0, 200, 200) : sf::IntRect(0, 200, 200, 200)) {

}
std::vector<vec2i> &King::getPossibleMoves(vec2i currentPos) {
  return possibleMoves_;
}
