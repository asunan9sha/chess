#include "basicbutton.hpp"
#include "resources/resourceholder.hpp"
#include <utility>
#include "renderers/masterrenderer.hpp"


ui::BasicButton::BasicButton(const std::string_view &string, const sf::Vector2f &size, const sf::Texture &texture,
                             std::function<void()> function) :
		function_(std::move(function)) {


	rectangleShape_.setSize(size);
	rectangleShape_.setTexture(&texture);
	rectangleShape_.setOutlineColor(sf::Color::Blue);
	rectangleShape_.setOutlineThickness(3.f);



	font_ = &ResourceHolder::getFont("CrimsonText-Bold.ttf");

	text_.setFont(*font_);
	text_.setFillColor(sf::Color::White);
	text_.setString(string.data());
	text_.setOutlineThickness(2.f);
	text_.setOutlineColor(sf::Color::Black);
	text_.setCharacterSize(60);
}

void ui::BasicButton::render(MasterRenderer *renderer) {
	//window.draw(rectangleShape);
	renderer->submit(text_);
}

void ui::BasicButton::setPos(const sf::Vector2f &vec) {
	rectangleShape_.setPosition(vec);
	text_.setPosition(vec);
	text_.move(rectangleShape_.getSize().x / 2 - text_.getLocalBounds().width / 2 ,
	          rectangleShape_.getSize().y / 2 - text_.getLocalBounds().height / 2 );
}

sf::Vector2f ui::BasicButton::getPos() const {
	return rectangleShape_.getPosition();
}

void ui::BasicButton::onClick() {
	function_();
}

void ui::BasicButton::onMouseHover() {
	rectangleShape_.setFillColor(sf::Color::Red);
	text_.setFillColor(sf::Color::Red);

}

void ui::BasicButton::onNoInteract() {
	rectangleShape_.setFillColor(sf::Color::White);
	text_.setFillColor(sf::Color::Blue);
}
void ui::BasicButton::input(const sf::Event &event) {

	if (hover(text_.getGlobalBounds())) {
		onMouseHover();
	} else {
		onNoInteract();
	}
	if(clicked(text_.getGlobalBounds(), event)){
		onClick();
	}
}
