#include "masterrenderer.hpp"

void MasterRenderer::submit(const sf::Drawable &drawable) {
	sfmlRenderer_.submit(drawable);
}

void MasterRenderer::flush() {
	sfmlRenderer_.flush();
}
