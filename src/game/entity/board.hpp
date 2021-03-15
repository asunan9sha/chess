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

  void movePiece(vec2 piecePos, vec2 destination);
  void clearPiece(vec2 piecePos);
  inline static float getCellSize() { return CELL_SIZE;}

private:
  void initBoard();

  std::shared_ptr<Piece> getPieceByType(PieceType type) const;
  std::shared_ptr<Piece> getUniquePiece(size_t x, size_t y) const;

public:
  static constexpr const float CELL_SIZE = 100.0f;

private:
  static constexpr const size_t BOARD_SIZE = 8;
  std::array<std::array<std::unique_ptr<Cell>, BOARD_SIZE>, BOARD_SIZE> board_;
  Cell* pickedCell_;
};


#endif
