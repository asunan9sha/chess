#ifndef CHESS_KNIGHT_HPP
#define CHESS_KNIGHT_HPP

#include "piece.hpp"


class Knight : public Piece {
public:
  explicit Knight(PieceType type);

  std::vector<vec2i> &getPossibleMoves(vec2i currentPos) override;
};


#endif
