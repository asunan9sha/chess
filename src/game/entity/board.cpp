#include "board.hpp"
#include "renderers/masterrenderer.hpp"
#include "resources/resourceholder.hpp"

Board::Board(const vec2 &pos, const vec2 &size, const sf::Texture &texture, float angle) {

  setPosition(pos.x, pos.y);
  setRotation(angle);
  setSize(size);
  setTexture(&texture);

  initBoard();
}

Board::~Board() {
  for (auto &p : pieces_) {
    delete p;
  }
}

void Board::render(MasterRenderer &renderer) {
  renderer.submit(*this);
}

void Board::input(const sf::Event &event) {
  for (const auto &p: pieces_) {
      p->input(event);
  }
}

void Board::update(float delta) {
  for (const auto &p : pieces_) {
    p->update(delta);
  }
}

void Board::fixedUpdate(float delta) {

}

void Board::initBoard() {
  float spacing = 100.0f;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      switch (board_[i][j]) {
        case 1:
          pieces_.push_back(
              new Pawn(PieceType::whitePawn, {50.0f + (spacing * j), 50.0f + (spacing * i)}, {100.0f, 100.0f}, {i, j},
                       ResourceHolder::getTexture("pieces.png")));
          break;
        case -1:
          pieces_.push_back(
              new Pawn(PieceType::blackPawn, {50.0f + (spacing * j), 50.0f + (spacing * i)}, {100.0f, 100.0f}, {i, j},
                       ResourceHolder::getTexture("pieces.png")));
          break;
        case 2:
          pieces_.push_back(
              new Knight(PieceType::whiteKnight, {50.0f + (spacing * j), 50.0f + (spacing * i)}, {100.0f, 100.0f},
                         ResourceHolder::getTexture("pieces.png")));
          break;
        case -2:
          pieces_.push_back(
              new Knight(PieceType::blackKnight, {50.0f + (spacing * j), 50.0f + (spacing * i)}, {100.0f, 100.0f},
                         ResourceHolder::getTexture("pieces.png")));
          break;
        case 3:
          pieces_.push_back(
              new Bishop(PieceType::whiteBishop, {50.0f + (spacing * j), 50.0f + (spacing * i)}, {100.0f, 100.0f},
                         ResourceHolder::getTexture("pieces.png")));
          break;
        case -3:
          pieces_.push_back(
              new Bishop(PieceType::blackBishop, {50.0f + (spacing * j), 50.0f + (spacing * i)}, {100.0f, 100.0f},
                         ResourceHolder::getTexture("pieces.png")));
          break;
        case 4:
          pieces_.push_back(
              new Rook(PieceType::whiteRook, {50.0f + (spacing * j), 50.0f + (spacing * i)}, {100.0f, 100.0f},
                       ResourceHolder::getTexture("pieces.png")));
          break;
        case -4:
          pieces_.push_back(
              new Rook(PieceType::blackRook, {50.0f + (spacing * j), 50.0f + (spacing * i)}, {100.0f, 100.0f},
                       ResourceHolder::getTexture("pieces.png")));
          break;
        case 5:
          pieces_.push_back(
              new King(PieceType::whiteKing, {50.0f + (spacing * j), 50.0f + (spacing * i)}, {100.0f, 100.0f},
                       ResourceHolder::getTexture("pieces.png")));
          break;
        case -5:
          pieces_.push_back(
              new King(PieceType::blackKing, {50.0f + (spacing * j), 50.0f + (spacing * i)}, {100.0f, 100.0f},
                       ResourceHolder::getTexture("pieces.png")));
          break;
        case 6:
          pieces_.push_back(
              new Queen(PieceType::whiteQueen, {50.0f + (spacing * j), 50.0f + (spacing * i)}, {100.0f, 100.0f},
                        ResourceHolder::getTexture("pieces.png")));
          break;
        case -6:
          pieces_.push_back(
              new Queen(PieceType::blackQueen, {50.0f + (spacing * j), 50.0f + (spacing * i)}, {100.0f, 100.0f},
                        ResourceHolder::getTexture("pieces.png")));
          break;
        default:break;
      }
    }
  }
}

vec2i Board::convertToInt(vec2 pos) {
  vec2i temp;
  temp.x = static_cast<int>((pos.x - 50.0f) / 100.0f);
  temp.y = static_cast<int>((pos.y - 50.0f) / 100.0f);
  return temp;
}
vec2 Board::convertToFloat(vec2i pos) {
  vec2 temp;
  temp.x = 50.0f + (pos.x * 100.0f);
  temp.y = 50.0f + (pos.y * 100.0f);
  return temp;
}

void Board::movePiece(vec2i piecePos, vec2i destination) {
  if (board_[piecePos.x][piecePos.y] != 0) {
    board_[destination.x][destination.y] = board_[piecePos.x][piecePos.y];
    board_[piecePos.x][piecePos.y] = 0;
  }
}
