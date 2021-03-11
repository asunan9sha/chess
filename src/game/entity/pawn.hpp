#ifndef CHESS_PAWN_HPP
#define CHESS_PAWN_HPP

#include "piece.hpp"

class Pawn : public Piece {
public:
  explicit Pawn(PieceType type, const vec2 &pos, const vec2 &size, const vec2i boardPos, const sf::Texture &texture);

  void update(float delta) override;
  void showMoves() override;
};


#endif //CHESS_PAWN_HPP
