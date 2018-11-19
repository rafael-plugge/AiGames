#pragma once

#include "BaseSystem.h"

namespace app::sys
{
	class CollisionSystem : public BaseSystem
	{
	public:
		CollisionSystem(app::Registry & registry, sf::Vector2f const & windowSize);

		virtual void update(app::seconds const & dt) override;

	private:
		sf::Vector2f const m_windowSize;
		float const m_boundary; // distance that a entity can be outside of the screen
	};

}