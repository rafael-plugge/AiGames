#include "stdafx.h"
#include "RenderVisitor.h"

app::visitor::RenderVisitor::RenderVisitor(sf::RectangleShape & rectangleShape)
	: _rectangleShape(rectangleShape)
{
}

void app::visitor::RenderVisitor::operator()(sf::Color const & color)
{
	_rectangleShape.setFillColor(color);
}

void app::visitor::RenderVisitor::operator()(std::shared_ptr<sf::Texture> sptrTexture)
{
	_rectangleShape.setTexture(sptrTexture.get());
}
