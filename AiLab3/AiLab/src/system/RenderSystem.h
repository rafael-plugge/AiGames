#pragma once

#include "BaseSystem.h"

namespace app::sys
{
	class RenderSystem : public BaseSystem
	{
	public:
		RenderSystem(app::Registry & registry, sf::RenderWindow& window);

		virtual void update(app::seconds const & dt) override;

	private:
		sf::RenderWindow& m_window;

		sf::RectangleShape m_renderShape;
		sf::RenderStates m_renderState;
	};

}