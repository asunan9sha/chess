#include <iostream>
#include "board.hpp"
#include "renderers/masterrenderer.hpp"
#include "resources/resourceholder.hpp"
#include "pawn.hpp"
#include "kninght.hpp"
#include "bishop.hpp"
#include "king.hpp"
#include "queen.hpp"
#include "rook.hpp"
#include "utils/assert.hpp"


Board::Board() : pickedCell_(nullptr) {
  initBoard();

  for (size_t i = 0; i < BOARD_SIZE; i++) {
    for (size_t j = 0; j < BOARD_SIZE; j++) {
      if (board_[i][j]->getPiece() && (board_[i][j]->getPiece()->getPosition().y / 100.0f) < 2) {
        board_[i][j]->getPiece()->setOnTop(true);
      }
    }
  }
}

void Board::render(MasterRenderer &renderer) {
  for (size_t i = 0; i < BOARD_SIZE; i++) {
    for (size_t j = 0; j < BOARD_SIZE; j++) {
      board_[i][j]->render(renderer);
    }
  }
}

void Board::input(const sf::Event &event) {
  if (event.type == sf::Event::MouseButtonPressed) {
    if (event.mouseButton.button == sf::Mouse::Left) {
      const int x = static_cast<int>(event.mouseButton.x / CELL_SIZE);
      const int y = static_cast<int>(event.mouseButton.y / CELL_SIZE);
      if (event.mouseButton.button == sf::Mouse::Left) {
        if (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE && getCell(x, y).isPeacePlaced() && !pickedCell_) {
          pickedCell_ = &getCell(x, y);
          pickedCell_->setFillColor(sf::Color::Green);
        } else if (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE && pickedCell_) {
          if (pickedCell_->getPosition().x == float(x) * 100.0f && pickedCell_->getPosition().y == y * 100.0f) {
            pickedCell_->setFillColor(pickedCell_->getOriginalColor());
            pickedCell_ = nullptr;
            return;
          }
          tryToMove(pickedCell_->getPiece()->getPosition(), {(float) x * 100.0f, (float) y * 100.0f});
          pickedCell_->setFillColor(pickedCell_->getOriginalColor());
          pickedCell_ = nullptr;
        }
      }
    }
  }
  if (event.mouseButton.button == sf::Mouse::Right && pickedCell_) {
    pickedCell_->setFillColor(pickedCell_->getOriginalColor());
    pickedCell_ = nullptr;
  }
}


void Board::update(float delta) {
  if (pickedCell_) {
    pickedCell_->getPiece()->update(delta);
  }
  for (size_t i = 0; i < BOARD_SIZE; i++) {
    for (size_t j = 0; j < BOARD_SIZE; j++) {
    }
  }
}

void Board::initBoard() {
  bool isWhite = true;
  for (size_t i = 0; i < BOARD_SIZE; i++) {
    for (size_t j = 0; j < BOARD_SIZE; j++) {
      std::shared_ptr<Piece> piece;
      if (i == 0 || i == BOARD_SIZE - 1) {
        piece = getUniquePiece(j, i);
      } else if (i == 1) {
        piece = getPieceByType(PieceType::whitePawn);
      } else if (i == BOARD_SIZE - 2) {
        piece = getPieceByType(PieceType::blackPawn);
      }

      const vec2 pos = {CELL_SIZE * static_cast<float>(j), CELL_SIZE * static_cast<float>(i)};
      board_[i][j] = std::make_unique<Cell>(std::move(piece), pos, isWhite);
      isWhite = !isWhite;
    }
    isWhite = !isWhite;
  }
}

std::shared_ptr<Piece> Board::getPieceByType(PieceType type) const {
  switch (type) {

    case PieceType::whitePawn:return std::make_shared<Pawn>(PieceType::whitePawn);
    case PieceType::whiteKnight:return std::make_shared<Knight>(PieceType::whiteKnight);
    case PieceType::whiteBishop:return std::make_shared<Bishop>(PieceType::whiteBishop);
    case PieceType::whiteRook:return std::make_shared<Rook>(PieceType::whiteRook);
    case PieceType::whiteKing:return std::make_shared<King>(PieceType::whiteKing);
    case PieceType::whiteQueen:return std::make_shared<Queen>(PieceType::whiteQueen);
    case PieceType::blackPawn:return std::make_shared<Pawn>(PieceType::blackPawn);
    case PieceType::blackKnight:return std::make_shared<Knight>(PieceType::blackKnight);
    case PieceType::blackBishop:return std::make_shared<Bishop>(PieceType::blackBishop);
    case PieceType::blackRook:return std::make_shared<Rook>(PieceType::blackRook);
    case PieceType::blackKing:return std::make_shared<King>(PieceType::blackKing);
    case PieceType::blackQueen:return std::make_shared<Queen>(PieceType::blackQueen);
  }
  return std::shared_ptr<Piece>();
}

std::shared_ptr<Piece> Board::getUniquePiece(size_t x, size_t y) const {
  const bool isWhite = y < BOARD_SIZE / 2;
  if (x == 0 || x == BOARD_SIZE - 1) {
    return getPieceByType(isWhite ? PieceType::whiteRook : PieceType::blackRook);
  }
  if (x == 1 || x == BOARD_SIZE - 2) {
    return getPieceByType(isWhite ? PieceType::whiteKnight : PieceType::blackKnight);
  }
  if (x == 2 || x == BOARD_SIZE - 3) {
    return getPieceByType(isWhite ? PieceType::whiteBishop : PieceType::blackBishop);
  }
  if (x == 3) {
    return getPieceByType(isWhite ? PieceType::whiteQueen : PieceType::blackQueen);
  }
  return getPieceByType(isWhite ? PieceType::whiteKing : PieceType::blackKing);
}

Cell &Board::getCell(size_t x, size_t y) {
  static Cell *empty = new Cell();
  if (x > BOARD_SIZE) {
    ASSERT(false);
    return *empty;
  }
  if (y > BOARD_SIZE) {
    ASSERT(false);
    return *empty;
  }
  return *board_[y][x];
}

void Board::tryToMove(vec2 piecePos, vec2 destination) {
  const int x = static_cast<int>(piecePos.x / CELL_SIZE);
  const int y = static_cast<int>(piecePos.y / CELL_SIZE);

  const auto type = board_[y][x]->getPiece()->getType();

//  for (const auto &m :  board_[piecePos.y / CELL_SIZE][piecePos.x / CELL_SIZE]->getPiece()->getPossibleMoves()) {
//    std::cout << "x move = " << m.x << " y move = " << m.y << std::endl;
//  }
//  std::cout << "-------------------------" << std::endl;

  if (type == PieceType::whitePawn || type == PieceType::blackPawn) {
    pawnMoves(piecePos, destination);
  } else if (type == PieceType::whiteKnight || type == PieceType::blackKnight) {
    knightMoves(piecePos, destination);
  } else if (type == PieceType::whiteRook || type == PieceType::blackRook) {
    rookMoves(piecePos, destination);
  }
}

void Board::movePiece(vec2i piecePos, vec2i destination) {
  board_[piecePos.x][piecePos.y]->moveTo(*board_[destination.y][destination.x]);
  board_[destination.y][destination.x]->getPiece()->pieceMoved();
  board_[destination.y][destination.x]->getPiece()->getPossibleMoves().clear();

  if (board_[destination.y][destination.x]->getPiece()->getType() == PieceType::whitePawn ||
      board_[destination.y][destination.x]->getPiece()->getType() == PieceType::blackPawn) {
    if (destination.y == 0 || destination.y == 7) {
      board_[destination.y][destination.x]->getPiece() = std::move(std::make_shared<Queen>(
          static_cast<int>(board_[destination.y][destination.x]->getPiece()->getType()) < 5 ? PieceType::whiteQueen
                                                                                            : PieceType::blackQueen));
      board_[destination.y][destination.x]->getPiece()->setPosition(destination.x * 100.0f, destination.y * 100.0f);
    }
  }
}

void Board::pawnMoves(vec2 piecePos, vec2 destination) {
  const int x = static_cast<int>(piecePos.x / CELL_SIZE);
  const int y = static_cast<int>(piecePos.y / CELL_SIZE);

  const int dx = static_cast<int>((destination.x / CELL_SIZE));
  const int dy = static_cast<int>(destination.y / CELL_SIZE);

  for (const auto &m :  board_[y][x]->getPiece()->getPossibleMoves()) {
    if (board_[y][x]->getPiece()->getType() == PieceType::whitePawn ||
        board_[y][x]->getPiece()->getType() == PieceType::blackPawn) {
      if (board_[m.y / CELL_SIZE][m.x / CELL_SIZE]->isPeacePlaced() && dx != x &&
          board_[y][x]->getPiece()->isWhite() != board_[dy][dx]->getPiece()->isWhite()) {
        movePiece({y, x}, {dx, dy});
        return;
      }
      if (getCell(m.x / CELL_SIZE, m.y / CELL_SIZE).isPeacePlaced()) {
        board_[y][x]->getPiece()->getPossibleMoves().clear();
        return;
      }
      if (board_[dy][dx]->getPosition() == m && m.x / CELL_SIZE == x) {
        movePiece({y, x}, {dx, dy});
        return;
      }
    }
  }
}

void Board::rookMoves(vec2 piecePos, vec2 destination) {
  const int x = static_cast<int>(piecePos.x / CELL_SIZE);
  const int y = static_cast<int>(piecePos.y / CELL_SIZE);

  const int dx = static_cast<int>((destination.x / CELL_SIZE));
  const int dy = static_cast<int>(destination.y / CELL_SIZE);

  for (const auto &m :  board_[y][x]->getPiece()->getPossibleMoves()) {
    if (board_[dy][dx]->getPosition() != m) {
      continue;
    }
    if (x != dx) {
      if (dx - x > 0 && dx - x != 1) {
        int tempX = static_cast<int>((board_[y][x]->getPiece()->getPosition().x + CELL_SIZE) / CELL_SIZE);
        while (tempX != dx) {
          if (!board_[dy][tempX]->isPeacePlaced()) {
            tempX += 1;
            continue;
          } else {
            return;
          }
        }
        if (tempX == dx) {
          movePiece({y, x}, {dx, dy});
          return;
        }
      } else if (abs(dx - x) != 1) {
        {
          int tempX = static_cast<int>((board_[y][x]->getPiece()->getPosition().x - CELL_SIZE) / CELL_SIZE);
          while (tempX != dx) {
            if (!board_[dy][tempX]->isPeacePlaced()) {
              tempX -= 1;
              continue;
            } else {
              return;
            }
          }
          if (tempX == dx) {
            movePiece({y, x}, {dx, dy});
            return;
          }
        }
      }
    } else if (y != dy) {
      if (dy - y > 0 && dy - y != 1) {
        int tempY = static_cast<int>((board_[y][x]->getPiece()->getPosition().y + CELL_SIZE) / CELL_SIZE);
        while (tempY != dy) {
          if (!board_[tempY][dx]->isPeacePlaced()) {
            tempY += 1;
            continue;
          } else {
            return;
          }
        }
        if (tempY == dy) {
          movePiece({y, x}, {dx, dy});
          return;
        }
      } else if(abs(dy - y) != 1) {
        {
          int tempY = static_cast<int>((board_[y][x]->getPiece()->getPosition().y - CELL_SIZE) / CELL_SIZE);
          while (tempY != dy) {
            if (!board_[tempY][dx]->isPeacePlaced()) {
              tempY -= 1;
              continue;
            } else {
              return;
            }
          }
          if (tempY == dy) {
            movePiece({y, x}, {dx, dy});
            return;
          }
        }
      }
    }
  }
  if (!board_[dy][dx]->isPeacePlaced()) {
    movePiece({y, x}, {dx, dy});
    return;
  }
  if (board_[y][x]->getPiece()->isWhite() != board_[dy][dx]->getPiece()->isWhite()) {
    movePiece({y, x}, {dx, dy});
    return;
  }
}


void Board::knightMoves(vec2 piecePos, vec2 destination) {
  const int x = static_cast<int>(piecePos.x / CELL_SIZE);
  const int y = static_cast<int>(piecePos.y / CELL_SIZE);

  const int dx = static_cast<int>((destination.x / CELL_SIZE));
  const int dy = static_cast<int>(destination.y / CELL_SIZE);

  for (const auto &m :  board_[y][x]->getPiece()->getPossibleMoves()) {
    if (m.x > 700 || m.x < 0 || m.y > 700 || m.y < 0) {
      continue;
    }
    if (board_[dy][dx]->getPosition() != m) {
      continue;
    }
    if (!board_[dy][dx]->isPeacePlaced()) {
      movePiece({y, x}, {dx, dy});
      return;
    }
    if (board_[y][x]->getPiece()->isWhite() != board_[dy][dx]->getPiece()->isWhite()) {
      movePiece({y, x}, {dx, dy});
      return;
    }
  }
}
