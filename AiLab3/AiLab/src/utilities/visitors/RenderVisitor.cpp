#include "stdafx.h"
#include "RenderVisitor.h"

app::visitor::RenderVisitor::RenderVisitor(sf::RectangleShape & rectangleShape)
	: _rectangleShape(rectangleShape)
{
}

void app::visitor::RenderVisitor::operator()(sf::Color const & color)
{
	_rectangleShape.setFillColor(color);
	_rectangleShape.setTexture(nullptr, true);
}

void app::visitor::RenderVisitor::operator()(std::shared_ptr<sf::Texture> sptrTexture)
{
	_rectangleShape.setFillColor(sf::Color::White);
	_rectangleShape.setTexture(sptrTexture.get(), true);
}
