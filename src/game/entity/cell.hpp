#ifndef CHESS_CELL_HPP
#define CHESS_CELL_HPP

#include "gameobject.hpp"
#include "piece.hpp"
#include <memory>

class Cell : public GameObject {
public:
  Cell() = default;
  Cell(std::shared_ptr<Piece> piece, const vec2 &pos, bool isWhite);
  void render(MasterRenderer &renderer) override;
  void input(const sf::Event &event) override { }
  void update(float delta) override { }

  void moveTo(Cell &targetCell);
  std::shared_ptr<Piece> &getPiece() { return piece_; }
  const std::shared_ptr<Piece> &getPiece() const { return piece_; }
  inline sf::Color getOriginalColor() const { return originalColor_; }

  bool getPieceColor();
  bool isPeacePlaced() const;
  inline void setPiece(bool isPeacePlaced) { isPiecePlaced_ = isPeacePlaced; }

  bool isWhite() const { return isWhite_; }

private:
  bool isWhite_ = true;
  std::shared_ptr<Piece> piece_;
  bool isPiecePlaced_;
  sf::Color originalColor_;
};


#endif
