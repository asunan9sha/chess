#ifndef CHESS_QUEEN_HPP
#define CHESS_QUEEN_HPP

#include "piece.hpp"


class Queen : public Piece {
public:
  explicit Queen(PieceType type);

  std::vector<vec2i> &getPossibleMoves(vec2i currentPos) override;
};


#endif
