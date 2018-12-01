#include "stdafx.h"
#include "RenderRectVisitor.h"



app::vis::RenderRectVisitor::RenderRectVisitor(sf::RectangleShape & renderShape)
	: m_renderShape(renderShape)
{
}

void app::vis::RenderRectVisitor::operator()(sf::Color const & color)
{
	m_renderShape.setTexture(nullptr, false);
	m_renderShape.setFillColor(color);
}

void app::vis::RenderRectVisitor::operator()(std::shared_ptr<sf::Texture> const & sptrTexture)
{
	m_renderShape.setFillColor(sf::Color::White);
	m_renderShape.setTexture(sptrTexture.get(), false);
}
