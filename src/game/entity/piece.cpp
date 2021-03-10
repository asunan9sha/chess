#include "piece.hpp"
#include "renderers/masterrenderer.hpp"
#include "board.hpp"
#include "iostream"

Piece::Piece(PieceType type, const vec2 &pos, const vec2 &size, const sf::Texture &texture) :
    pieceType_(type), isPicked_(false) {

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

      if (fabs(getPosition().x - mousePos.x) < 50.0f && fabs(getPosition().y - mousePos.y) < 50.0f) {
        std::cout << "difference x = " << fabs(getPosition().x - mousePos.x) << " " << "difference y = "
                  << fabs(getPosition().y - mousePos.y) << std::endl;
        std::cout << "piece type = " << static_cast<int>(pieceType_) << std::endl;
        pickedPiece_ = this;
      }
    }
    if (event.mouseButton.button == sf::Mouse::Right) {
      pickedPiece_ = nullptr;
    }
  }
}

void Piece::pick() {
  isPicked_ = true;
}

void Piece::unPick() {
  isPicked_ = false;
}
