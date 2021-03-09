#ifndef CHESS_BASICBUTTON_HPP
#define CHESS_BASICBUTTON_HPP


#include "button.hpp"
#include <string>
#include <functional>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

namespace ui {
	class BasicButton : public Button {

	public:
		BasicButton(const std::string_view &text, const sf::Vector2f &size, const sf::Texture &texture,
		            std::function<void()> function);

		void render(MasterRenderer *renderer) override;

		void setPos(const sf::Vector2f &vec) override;

		void input(const sf::Event &event) override;

		sf::Vector2f getPos() const override;
	private:

		void onClick() override;

		void onMouseHover() override;

		void onNoInteract() override;


	private:
		sf::Text text_;
		sf::RectangleShape rectangleShape_;
		std::function<void()> function_;

		const sf::Font *font_;
	};
}


#endif
