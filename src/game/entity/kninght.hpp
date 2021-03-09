#ifndef CHESS_KNIGHT_HPP
#define CHESS_KNIGHT_HPP

#include "piece.hpp"


class Knight : public Piece {
public:
  explicit Knight(PieceType type, const vec2 &pos, const vec2 &size, const sf::Texture &texture);

  void move() override;
};


#endif
