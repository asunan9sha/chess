#include <iostream>
#include "pawn.hpp"

Pawn::Pawn(PieceType type)
   : Piece(type, type == PieceType::whitePawn? sf::IntRect(1000, 0, 200, 200) : sf::IntRect(1000, 200, 200, 200)) {

}

void Pawn::update(float delta) {
  if (pickedPiece_) {
    showMoves();
  } else {
    clearMoves();
  }
}

void Pawn::showMoves() {
  circleShapes_.clear();
  if (pickedPiece_) {
//    if(Board::getByIndex(pickedPiece_->getBoardPos().x,pickedPiece_->getBoardPos().y - (pickedPiece_->getType() == PieceType::whitePawn? -1 : 1)) == 0 && ) {
//
//    }
    if (!isMoved_) {
      circleShapes_.push_back(new sf::CircleShape(50));
      circleShapes_.push_back(new sf::CircleShape(50));
    } else {
      circleShapes_.clear();
      circleShapes_.push_back(new sf::CircleShape(50));
    }

    float spacingWhite = -150.0f;;
    float spacingBlack = 50.0f;;

    for (auto &c : circleShapes_) {
      c->setPosition(pickedPiece_->getPosition().x - 50.0f, pickedPiece_->getPosition().y + (pickedPiece_->getType() == PieceType::whitePawn ? spacingWhite : spacingBlack));
      c->setFillColor(sf::Color(0, 0, 0, 150));
        spacingWhite -= 100.0f;
        spacingBlack += 100.0f;
      }
    }
  }
