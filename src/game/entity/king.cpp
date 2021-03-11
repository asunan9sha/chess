#include "king.hpp"

King::King(PieceType type)
  : Piece(type, type == PieceType::whiteKing? sf::IntRect(0, 0, 200, 200) : sf::IntRect(0, 200, 200, 200)) {

}
