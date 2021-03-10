#include "pawn.hpp"
#include "board.hpp"

Pawn::Pawn(PieceType type, const vec2 &pos, const vec2 &size, const vec2i boardPos, const sf::Texture &texture)
    : Piece(type, pos, size, texture) {

  boardPos_ = boardPos;

  if (Pawn::getType() == PieceType::whitePawn) {
    setTextureRect(sf::IntRect(1000, 0, 200, 200));
  } else {
    setTextureRect(sf::IntRect(1000, 200, 200, 200));
  }
}

void Pawn::update(float delta) {
  if (pickedPiece_) {
    showMoves();
  } else {
    clearMoves();
  }
}

void Pawn::move() {
  if (pickedPiece_) {
//    Board::movePiece(pickedPiece_->getBoardPos(), )
  }
}

void Pawn::showMoves() {
  circleShapes_.clear();
  if (pickedPiece_) {
    if (!isMoved_) {
      circleShapes_.push_back(new sf::CircleShape(50));
      circleShapes_.push_back(new sf::CircleShape(50));
    } else {
      circleShapes_.push_back(new sf::CircleShape(50));
    }

    float temp;
    if (pickedPiece_->getType() == PieceType::whitePawn) {
      temp = -150.0f;
    } else {
      temp = 150.0f;
    }

    for (auto &c : circleShapes_) {
      c->setPosition(pickedPiece_->getPosition().x - 50.0f, pickedPiece_->getPosition().y + temp);
      c->setFillColor(sf::Color(0, 0, 0, 150));
      if (pickedPiece_->getType() == PieceType::whitePawn) {
        temp -= 100.0f;
      } else {
        temp -= 100.0f;
      }
    }
  }
}

void Pawn::clearMoves() {
  pickedPiece_ = nullptr;
  circleShapes_.clear();
}
