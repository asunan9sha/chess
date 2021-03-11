#ifndef CHESS_BISHOP_HPP
#define CHESS_BISHOP_HPP

#include "piece.hpp"


class Bishop : public Piece {
public:
  explicit Bishop(PieceType type);
  void showMoves() override {}
  void clearMoves() override {}
};


#endif
