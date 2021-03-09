#include "component.hpp"
#include "app/application.hpp"

bool ui::Component::hover(const sf::FloatRect &shape) {
	return shape.contains(
			sf::Mouse::getPosition(Application::getApplication().getWindow().raw()).x,
			sf::Mouse::getPosition(Application::getApplication().getWindow().raw()).y);
}

bool ui::Component::clicked(const sf::FloatRect &shape, const sf::Event &event) {
	if (hover(shape)) {
		if (event.type == sf::Event::MouseButtonPressed) {
			return event.mouseButton.button == sf::Mouse::Button::Left;
		}

	}
	return false;
}
