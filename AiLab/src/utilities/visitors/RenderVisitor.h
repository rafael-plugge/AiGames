#pragma once

namespace app::visitor
{
	class RenderVisitor
	{
	public:
		RenderVisitor(sf::RectangleShape & rectangleShape);

		void operator()(sf::Color const & color);
		void operator()(std::shared_ptr<sf::Texture> sptrTexture);

	private:
		sf::RectangleShape & _rectangleShape;
	};

}