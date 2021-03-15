#ifndef CHESS_PIECE_HPP
#define CHESS_PIECE_HPP

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include "gameobject.hpp"
#include "utils/types.hpp"
#include "app/window.hpp"

enum class PieceType {
  whitePawn = 0,
  whiteKnight,
  whiteBishop,
  whiteRook,
  whiteKing,
  whiteQueen,
  blackPawn,
  blackKnight,
  blackBishop,
  blackRook,
  blackKing,
  blackQueen
};


class Piece : public GameObject {
public:
  explicit Piece(PieceType type, const sf::IntRect &rect);

  void render(MasterRenderer &renderer) override;
  void input(const sf::Event &event) override { }
  void update(float delta) override { }
  void copy(const Piece &other);

  virtual std::vector<vec2i> &getPossibleMoves(vec2i currentPos) = 0;

  inline PieceType getType() const { return pieceType_; }

  void pick();
  void unpick();

private:
  PieceType pieceType_;

  static constexpr const char *ATLAS = "pieces.png";

protected:
  std::vector<vec2i> possibleMoves_;

  bool isMoved_;
  bool isPicked_;
};


#endif
