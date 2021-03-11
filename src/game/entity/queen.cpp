#include "queen.hpp"

Queen::Queen(PieceType type)
    : Piece(type, type == PieceType::whiteQueen ? sf::IntRect(200, 0, 200, 200) : sf::IntRect(200, 200, 200, 200)) {

}
