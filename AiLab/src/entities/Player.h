#pragma once

#include "collisions/Collisions.h"

namespace g
{
	class Player
	{
	public:
		Player(sf::RenderWindow & window);
		~Player();

		void update();
		void render();

		void incrementSpeedKey(bool const & pressed) { _incrementSpeed = pressed; }
		void incrementSpeedKey(bool && pressed) { _incrementSpeed = std::move(pressed); }

		void decrementSpeedKey(bool const & pressed) { _decrementSpeed = pressed; }
		void decrementSpeedKey(bool && pressed) { _decrementSpeed = std::move(pressed); }

	private: // member variables
		sf::RenderWindow & _window;

		// input
		bool _incrementSpeed;
		bool _decrementSpeed;

		sf::RectangleShape _renderShape;
		sf::Vector2f _position;
		float _speed;
		sf::Vector2f _velocityDir;

	private: // static variables
		static constexpr float _Acceleration = 0.1f;
	};
}
