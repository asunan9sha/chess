#ifndef CHESS_BOARD_HPP
#define CHESS_BOARD_HPP

#include <array>
#include "gameobject.hpp"
#include "piece.hpp"
#include "cell.hpp"

class Board : public GameObject {
public:
  explicit Board();

  void render(MasterRenderer &renderer) override;
  void input(const sf::Event &event) override;
  void update(float delta) override;

  Cell &getCell(size_t x, size_t y);

  void pawnMoves(vec2 piecePos, vec2 destination);
  void rookMoves(vec2 piecePos, vec2 destination);
  void knightMoves(vec2 piecePos, vec2 destination);
  void tryToMove(vec2 piecePos, vec2 destination);
  void movePiece(vec2i piecePos, vec2i destination);
  static float getCellSize() { return CELL_SIZE; }

private:
  void initBoard();

  std::shared_ptr<Piece> getPieceByType(PieceType type) const;
  std::shared_ptr<Piece> getUniquePiece(size_t x, size_t y) const;

public:
  static constexpr const float CELL_SIZE = 100.0f;
  static constexpr const size_t BOARD_SIZE = 8;

private:
  std::array<std::array<std::unique_ptr<Cell>, BOARD_SIZE>, BOARD_SIZE> board_;
  Cell *pickedCell_;
};


#endif
