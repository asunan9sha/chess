#ifndef CHESS_ROOK_HPP
#define CHESS_ROOK_HPP

#include "piece.hpp"


class Rook : public Piece {
public:
  explicit Rook(PieceType type);

  std::vector<vec2i> &getPossibleMoves(vec2i currentPos) override;
};


#endif
