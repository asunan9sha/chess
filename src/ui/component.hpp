#ifndef CHESS_COMPONENT_HPP
#define CHESS_COMPONENT_HPP

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Shape.hpp>

class MasterRenderer;

namespace ui {

	class Component {

	public:

		virtual void input(const sf::Event &event) =0;
		virtual void update(float delta) =0;
		virtual void render(MasterRenderer *renderer)=0;

		virtual void setPos(const sf::Vector2f &vec)=0;
		virtual sf::Vector2f getPos() const =0;

		bool hover(const sf::FloatRect &shape);
		bool clicked(const sf::FloatRect &shape, const sf::Event &event);

	};
}

#endif
