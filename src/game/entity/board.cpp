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
#include "utils/random.hpp"


Board::Board() : pickedCell_(nullptr) {
  initBoard();
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
        if (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE && getCell(x, y).isPeacePlaced()) {
          pickedCell_ = &getCell(x, y);
          std::cout<<"placed peace x ="<< getCell(x, y).getPosition().x <<" "<<"placed peace y ="<< getCell(x, y).getPosition().y<<std::endl;
        }
      }
    }
    if (event.mouseButton.button == sf::Mouse::Right) {
      pickedCell_ = nullptr;
    }
  }
}

void Board::update(float delta) {
  for (size_t i = 0; i < BOARD_SIZE; i++) {
    for (size_t j = 0; j < BOARD_SIZE; j++) {
      board_[i][j]->update(delta);
      if(board_[i][j]->isPeacePlaced() && pickedCell_ ){
        board_[i][j]->getPiece().showMoves();
      }
    }
  }
}

void Board::initBoard() {
  bool isWhite = true;
  for (size_t i = 0; i < BOARD_SIZE; i++) {
    for (size_t j = 0; j < BOARD_SIZE; j++) {
      std::unique_ptr<Piece> piece = nullptr;
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

void Board::movePiece(vec2i piecePos, vec2i destination) {
//  if (board_[piecePos.x][piecePos.y] != 0) {
//    board_[destination.x][destination.y] = board_[piecePos.x][piecePos.y];
//    board_[piecePos.x][piecePos.y] = 0;
//  }
}

std::unique_ptr<Piece> Board::getPieceByType(PieceType type) const {
  switch (type) {

    case PieceType::whitePawn:return std::make_unique<Pawn>(PieceType::whitePawn);
    case PieceType::whiteKnight:return std::make_unique<Knight>(PieceType::whiteKnight);
    case PieceType::whiteBishop:return std::make_unique<Bishop>(PieceType::whiteBishop);
    case PieceType::whiteRook:return std::make_unique<Rook>(PieceType::whiteRook);
    case PieceType::whiteKing:return std::make_unique<King>(PieceType::whiteKing);
    case PieceType::whiteQueen:return std::make_unique<Queen>(PieceType::whiteQueen);
    case PieceType::blackPawn:return std::make_unique<Pawn>(PieceType::blackPawn);
    case PieceType::blackKnight:return std::make_unique<Knight>(PieceType::blackKnight);
    case PieceType::blackBishop:return std::make_unique<Bishop>(PieceType::blackBishop);
    case PieceType::blackRook:return std::make_unique<Rook>(PieceType::blackRook);
    case PieceType::blackKing:return std::make_unique<King>(PieceType::blackKing);
    case PieceType::blackQueen:return std::make_unique<Queen>(PieceType::blackQueen);
  }
  return std::unique_ptr<Piece>();
}

std::unique_ptr<Piece> Board::getUniquePiece(size_t x, size_t y) const {
  const bool isWhite = y < BOARD_SIZE / 2L;
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