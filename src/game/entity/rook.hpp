#ifndef CHESS_ROOK_HPP
#define CHESS_ROOK_HPP

#include "piece.hpp"


class Rook : public Piece {
public:
  explicit Rook(PieceType type);
  void showMoves() override;
  void clearMoves() override { }
};


#endif
