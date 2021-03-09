#ifndef CHESS_PIECE_HPP
#define CHESS_PIECE_HPP

#include <SFML/Window/Event.hpp>
#include "gameobject.hpp"
#include "piecetype.hpp"
#include "utils/types.hpp"


class Piece : public GameObject {
public:
  explicit Piece(PieceType type, const vec2 &pos, const vec2 &size, const sf::Texture &texture, float angle = 0);

  void render(MasterRenderer &renderer) override;
  void input(const sf::Event &event) override { }
  void update(float delta) override { }

  virtual void move() = 0;
  void pick();
  void unPick();

  virtual inline PieceType getType() const { return pieceType_; }

private:
  PieceType pieceType_;
  bool isPicked_;
};


#endif
