#ifndef CHESS_PAWN_HPP
#define CHESS_PAWN_HPP

#include "piece.hpp"


class Pawn : public Piece {
public:
  explicit Pawn(PieceType type);

  std::vector<vec2> &getPossibleMoves() override;
};


#endif
