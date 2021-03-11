#ifndef CHESS_CELL_HPP
#define CHESS_CELL_HPP

#include "gameobject.hpp"
#include "piece.hpp"
#include <memory>

class Cell : public GameObject {
public:
  Cell() = default;
  Cell(std::unique_ptr<Piece> piece, const vec2 &pos, bool isWhite);
  void render(MasterRenderer &renderer) override;
  void input(const sf::Event &event) override {}
  void update(float delta) override {}

  Piece &getPiece() { return *piece_; }
  const Piece &getPiece() const { return *piece_; }

  bool isWhite() const { return isWhite_; }

  //bool isEmpty() { return }

private:
  bool isWhite_ = true;
  std::unique_ptr<Piece> piece_;
};


#endif
