#pragma once

namespace app::comp
{
	struct Render
	{
		std::variant<sf::Color, std::shared_ptr<sf::Texture>> texture;
		sf::Vector2f size = { 10.0f, 10.0f };
	};
}