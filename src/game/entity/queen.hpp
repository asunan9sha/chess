#ifndef CHESS_QUEEN_HPP
#define CHESS_QUEEN_HPP


#include "piece.hpp"
#include "rook.hpp"
#include "bishop.hpp"

class Queen : public Piece {
public:
  explicit Queen(PieceType type);

  std::vector<vec2> &getPossibleMoves() override;
};


#endif
