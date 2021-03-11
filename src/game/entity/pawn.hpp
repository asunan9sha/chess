#ifndef CHESS_PAWN_HPP
#define CHESS_PAWN_HPP

#include "piece.hpp"


class Pawn : public Piece {
public:
  explicit Pawn(PieceType type);

  void update(float delta) override;
  void showMoves() override;
};


#endif
