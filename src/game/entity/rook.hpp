#ifndef CHESS_ROOK_HPP
#define CHESS_ROOK_HPP

#include "piece.hpp"


class Rook : public Piece {
public:
  explicit Rook(PieceType type, const vec2 &pos, const vec2 &size, const sf::Texture &texture);

  void move() override;
};


#endif
