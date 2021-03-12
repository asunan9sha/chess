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

  bool getPieceColor();
  inline bool isPeacePlaced() const { return isPiecePlaced_;}

  bool isWhite() const { return isWhite_; }

private:
  bool isWhite_ = true;
  std::unique_ptr<Piece> piece_;
  bool isPiecePlaced_;
};


#endif
