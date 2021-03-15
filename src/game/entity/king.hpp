#ifndef CHESS_KING_HPP
#define CHESS_KING_HPP

#include "piece.hpp"


class King : public Piece {
public:
  explicit King(PieceType type);

  std::vector<vec2i> &getPossibleMoves(vec2i currentPos) override;
};


#endif
