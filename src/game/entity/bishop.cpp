#include "bishop.hpp"

Bishop::Bishop(PieceType type)
    : Piece(type, type == PieceType::whiteBishop ? sf::IntRect(400, 0, 200, 200) : sf::IntRect(400, 200, 200, 200)) {

}
