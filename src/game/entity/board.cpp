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
          if (pickedCell_) {
            movePiece(pickedCell_->getPiece()->getPosition(), pickedCell_->getPiece()->getPosition());
            pickedCell_->setFillColor(pickedCell_->getOriginalColor());
            pickedCell_ = nullptr;
          } else {
            pickedCell_ = &getCell(x, y);
            pickedCell_->getPiece()->pick();
            pickedCell_->setFillColor(sf::Color::Green);
          }
        }
      }
    }
  }
  if (event.mouseButton.button == sf::Mouse::Right && pickedCell_) {
    pickedCell_->setFillColor(pickedCell_->getOriginalColor());
    pickedCell_->getPiece()->unpick();
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

void Board::movePiece(vec2 piecePos, vec2 destination) {
  const int y = static_cast<int>(piecePos.x / CELL_SIZE);
  const int x = static_cast<int>(piecePos.y / CELL_SIZE);

  const int dx = static_cast<int>((destination.x / CELL_SIZE)-1);
  const int dy = static_cast<int>((destination.y / CELL_SIZE));
  std::cout<<"y= "<<y<<"x= "<<x<<std::endl;
  board_[x][y]->moveTo(*board_[dy][dx]);


  //board_[y][x]->getPiece().setPosition({100.0f * (float)y, 100.0f * (float)x});
//  pickedCell_->setFillColor(pickedCell_->getOriginalColor());
//  pickedCell_ = nullptr;
//  sf::Color cellColor = board_[x][y]->getOriginalColor();
//  sf::Color destinationColor = board_[destination.x][destination.y]->getOriginalColor();
 }

void Board::clearPiece(vec2 piecePos) {
  const int x = static_cast<int>(piecePos.x / CELL_SIZE);
  const int y = static_cast<int>(piecePos.y / CELL_SIZE);

  std::unique_ptr<Piece> piece;

  board_[y][x] = std::make_unique<Cell>(std::move(piece), piecePos, board_[y][x]->isWhite());
}

