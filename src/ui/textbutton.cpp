#include "basicbutton.hpp"
#include "resources/resourceholder.hpp"
#include <utility>
#include "textbutton.hpp"
#include "renderers/masterrenderer.hpp"

ui::TextButton::TextButton(const std::string_view &string, std::function<void()> function) :
		function_(std::move(function)) {


	font_ = &ResourceHolder::getFont("dpcomic.ttf");


	text_.setFont(*font_);
	text_.setFillColor(sf::Color::White);
	text_.setString(string.data());
	text_.setOutlineThickness(2.f);
	text_.setOutlineColor(sf::Color::Black);
	text_.setCharacterSize(80);
}

void ui::TextButton::render(MasterRenderer *renderer) {
	renderer->submit(text_);
}

void ui::TextButton::setPos(const sf::Vector2f &vec) {
	rectangleShape_.setPosition(vec);
	text_.setPosition(vec);
	text_.move(rectangleShape_.getSize().x / 2 - text_.getLocalBounds().width / 2 ,
	          rectangleShape_.getSize().y / 2 - text_.getLocalBounds().height / 2 );
}

sf::Vector2f ui::TextButton::getPos() const {
	return rectangleShape_.getPosition();
}

void ui::TextButton::onClick() {
	function_();
}

void ui::TextButton::onMouseHover() {
	rectangleShape_.setFillColor(sf::Color::Red);
	text_.setFillColor(sf::Color::Red);

}

void ui::TextButton::onNoInteract() {
	rectangleShape_.setFillColor(sf::Color::White);
	text_.setFillColor(sf::Color::Blue);
}
void ui::TextButton::input(const sf::Event &event) {

	if (hover(text_.getGlobalBounds())) {
		onMouseHover();
	} else {
		onNoInteract();
	}
	if(clicked(text_.getGlobalBounds(), event)){
		onClick();
	}
}
