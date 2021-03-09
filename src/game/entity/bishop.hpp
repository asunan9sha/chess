#ifndef CHESS_BISHOP_HPP
#define CHESS_BISHOP_HPP

#include "piece.hpp"


class Bishop : public Piece {
public:
  explicit Bishop(PieceType type, const vec2 &pos, const vec2 &size, const sf::Texture &texture);

  void move() override;
};


#endif
