#ifndef CHESS_QUEEN_HPP
#define CHESS_QUEEN_HPP

#include "piece.hpp"


class Queen : public Piece {
public:
  explicit Queen(PieceType type);
  void showMoves() override {}
  void clearMoves() override {}
};


#endif
