#include "kninght.hpp"

Knight::Knight(PieceType type)
: Piece(type, type == PieceType::whiteKnight ? sf::IntRect(600, 0, 200, 200) : sf::IntRect(600, 200, 200, 200)) {

}
