#ifndef CHESS_BUTTON_HPP
#define CHESS_BUTTON_HPP

#include "component.hpp"
#include <SFML/Graphics/RectangleShape.hpp>
#include <tuner.h>

namespace ui {

	class Button : public Component {

	public:

		void update(float delta) override {		}

	protected:
		explicit Button() = default;

	private:
		virtual void onClick()=0;
		virtual void onMouseHover()=0;
		virtual void onNoInteract()=0;


	};
}

#endif
