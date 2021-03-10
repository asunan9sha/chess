#ifndef CHESS_PIECE_HPP
#define CHESS_PIECE_HPP

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include "gameobject.hpp"
#include "piecetype.hpp"
#include "utils/types.hpp"
#include "app/window.hpp"


class Piece : public GameObject {
public:
  explicit Piece(PieceType type, const vec2 &pos, const vec2 &size, const sf::Texture &texture);

  void render(MasterRenderer &renderer) override;
  void input(const sf::Event &event) override;
  void update(float delta) override { }

  virtual void move() = 0;
  virtual void showMoves() = 0;
  virtual void clearMoves() = 0;

  virtual

  inline bool picked() { return isPicked_; }

  virtual inline PieceType getType() const { return pieceType_; }
  inline std::vector<sf::CircleShape *> getCircles() { return circleShapes_; }
  inline static Piece* getPickedPiece() { return pickedPiece_; }
  inline vec2i getBoardPos() { return boardPos_;}

private:
  PieceType pieceType_;

protected:
  std::vector<sf::CircleShape *> circleShapes_;
  std::vector<vec2i> circleBoardPos_;
  vec2i boardPos_;

  bool isPicked_;
  bool isMoved_;
  inline static Piece *pickedPiece_ = nullptr;
};


#endif
