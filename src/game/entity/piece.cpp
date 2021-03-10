#include "piece.hpp"
#include "renderers/masterrenderer.hpp"
#include "board.hpp"
#include "iostream"

Piece::Piece(PieceType type, const vec2 &pos, const vec2 &size, const sf::Texture &texture) :
    pieceType_(type), isPicked_(false), isMoved_(false) {

  setOrigin(size.x / 2, size.y / 2);
  setPosition(pos.x, pos.y);
  setSize(size);
  setTexture(&texture);
}

void Piece::render(MasterRenderer &renderer) {
  renderer.submit(*this);
}

void Piece::input(const sf::Event &event) {
  if (event.type == sf::Event::MouseButtonPressed) {
    if (event.mouseButton.button == sf::Mouse::Left) {
      auto mousePos = sf::Mouse::getPosition(Window::get().raw());
      if (!pickedPiece_) {
        if (fabs(getPosition().x - mousePos.x) < 50.0f && fabs(getPosition().y - mousePos.y) < 50.0f) {
          pickedPiece_ = this;
        }
      } else {
        for (const auto &c : getCircles()) {
          if (fabs((c->getPosition().x + 50.0f) - mousePos.x) < 50.0f &&
              fabs((c->getPosition().y + 50.0f) - mousePos.y) < 50.0f) {
            Board::movePiece(pickedPiece_->getBoardPos(), {static_cast<int>((c->getPosition().x - 50.0f) / 100.0f),
                                                           static_cast<int>((c->getPosition().y - 50.0f) / 100.0f)});
            pickedPiece_->setPosition(c->getPosition().x + 50.0f, c->getPosition().y + 50.0f);
            pickedPiece_->isMoved_ = true;
            clearMoves();
          }
        }

      }
    }
    if (event.mouseButton.button == sf::Mouse::Right) {
      pickedPiece_ = nullptr;
    }
  }
}