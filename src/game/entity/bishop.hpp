#ifndef CHESS_BISHOP_HPP
#define CHESS_BISHOP_HPP

#include "piece.hpp"


class Bishop : public Piece {
public:
  explicit Bishop(PieceType type);
  std::vector<vec2> &getPossibleMoves() override;
};


#endif
