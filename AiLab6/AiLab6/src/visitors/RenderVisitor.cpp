#include "stdafx.h"
#include "RenderVisitor.h"

app::vis::RenderVisitor::RenderVisitor(js::json & j)
	: m_json(j)
{
}

void app::vis::RenderVisitor::operator()(sf::Color const & color)
{
	m_json["red"] = color.r;
	m_json["green"] = color.g;
	m_json["blue"] = color.b;
	m_json["alpha"] = color.a;
}

void app::vis::RenderVisitor::operator()(std::shared_ptr<sf::Texture> const & sptrTexture)
{
}
