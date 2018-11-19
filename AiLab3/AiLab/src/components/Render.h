#pragma once

namespace app::comp
{
	struct Render
	{
		std::variant<sf::Color, std::shared_ptr<sf::Texture>> texture = nullptr;
	};
}