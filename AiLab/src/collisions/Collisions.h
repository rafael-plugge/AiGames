#pragma once

namespace app
{
	class Collisions abstract
	{
	public:
		Collisions() = delete;
		
		static void LoopInWindow(sf::Vector2u const & windowSize, sf::Vector2f & position, sf::Vector2f const & size);
		static void LoopInWindow(sf::Vector2f const & windowSize, sf::Vector2f & position, sf::Vector2f const & size);
	};

}