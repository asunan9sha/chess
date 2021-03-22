#ifndef CHESS_PIECE_HPP
#define CHESS_PIECE_HPP

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include "gameobject.hpp"
#include "app/window.hpp"

enum class PieceType {
  whitePawn = 0,
  whiteKnight,
  whiteBishop,
  whiteRook,
  whiteQueen,
  whiteKing,
  blackPawn,
  blackKnight,
  blackBishop,
  blackRook,
  blackQueen,
  blackKing

};


class Piece : public GameObject {
public:
  explicit Piece(PieceType type, const sf::IntRect &rect);
  void render(MasterRenderer &renderer) override;
  void input(const sf::Event &event) override { }
  void update(float delta) override { }
  void copy(const Piece &other);

  virtual std::vector<vec2> &getPossibleMoves() = 0;

  void pieceMoved() { isMoved_ = true; }
  void setOnTop(bool isOnTop) { isOnTop_ = isOnTop; }

  bool isWhite() const { return isWhite_; }
  PieceType getType() const { return pieceType_; }

private:
  PieceType pieceType_;

  static constexpr const char *ATLAS = "pieces.png";

protected:
  std::vector<vec2> possibleMoves_;

  bool isMoved_;
  bool isOnTop_;
  bool isWhite_;
};


#endif
