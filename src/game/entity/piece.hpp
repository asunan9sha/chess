#ifndef CHESS_PIECE_HPP
#define CHESS_PIECE_HPP

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include "gameobject.hpp"
#include "utils/types.hpp"
#include "app/window.hpp"

enum class PieceType {
  none = 0,
  whitePawn,
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
  void input(const sf::Event &event) override;
  void update(float delta) override { }

  virtual void showMoves() = 0;
  virtual void clearMoves();

  virtual inline PieceType getType() const { return pieceType_; }
  inline std::vector<sf::CircleShape *> getCircles() { return circleShapes_; }
  inline  Piece* getPickedPiece() { return pickedPiece_; }

  inline vec2i getBoardPos() { return boardPos_;}

private:
  PieceType pieceType_;

  static constexpr const char* ATLAS = "pieces.png";

protected:
  std::vector<sf::CircleShape *> circleShapes_;
  vec2i boardPos_;

  bool isMoved_;
  Piece *pickedPiece_;
};


#endif
