#ifndef CHESS_PAWN_HPP
#define CHESS_PAWN_HPP

#include "piece.hpp"


class Pawn : public Piece {
public:
  explicit Pawn(PieceType type, const vec2 &pos, const vec2 &size, const sf::Texture &texture);

  void move() override;
  void moveS(Piece& piece);
  void showMoves();
};


#endif //CHESS_PAWN_HPP
