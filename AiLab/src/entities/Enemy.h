#pragma once

#include "collisions/Collisions.h"

namespace g
{
	class Enemy
	{
	public:
		Enemy(sf::RenderWindow & window);

		void update();
		void render();

		void generateNewDirection();
	private: // member variables
		sf::RenderWindow & _window;

		sf::RectangleShape _renderShape;
		sf::Vector2f _position;
		float _speed;
		sf::Vector2f _velocityDir;

	private: // static variables
		static std::default_random_engine _randomGeneratorEngine;
		static std::uniform_real_distribution<float> _randomDistribution;
		static const float randomAngle();
	};
}