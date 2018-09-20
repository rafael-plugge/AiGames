#include "stdafx.h"
#include "Collisions.h"


void app::Collisions::LoopInWindow(sf::Vector2u const & windowSize, sf::Vector2f & position, sf::Vector2f const & size)
{
	app::Collisions::LoopInWindow(static_cast<sf::Vector2f>(windowSize), position, size);
}

void app::Collisions::LoopInWindow(sf::Vector2f const & windowSize, sf::Vector2f & position, sf::Vector2f const & size)
{
	if (position.x + size.x < 0.0f) { position.x = windowSize.x; }
	if (position.x > windowSize.x) { position.x = -size.x; }
	if (position.y + size.y < 0.0f) { position.y = windowSize.y; }
	if (position.y > windowSize.y) { position.y = -size.y; }
}
