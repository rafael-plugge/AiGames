#pragma once

namespace app::comp
{
	struct Motion
	{
		sf::Vector2f velocity = { 0.0f, 0.0f };
		float angularSpeed = 0.0f;
	};
}