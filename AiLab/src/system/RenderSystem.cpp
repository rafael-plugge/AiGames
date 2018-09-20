#include "stdafx.h"
#include "RenderSystem.h"
#include "components/Location.h"
#include "components/Render.h"
#include "utilities/RenderVisitor.h"

app::sys::RenderSystem::RenderSystem(app::Registry & registry, sf::RenderWindow & window)
	: BaseSystem(registry)
	, m_window(window)
	, m_renderShape({ 10.0f, 10.0f })
	, m_renderState(sf::RenderStates::Default)
{
}

void app::sys::RenderSystem::update(app::seconds const & dt)
{
	auto view = m_registry.view<comp::Location, comp::Render>();
	view.each([this](auto entity, comp::Location & location, comp::Render & render) -> void
	{
		m_renderShape.setPosition(location.position);
		m_renderShape.setRotation(location.angle);
		m_renderShape.setSize(render.size);
		std::visit(visitor::RenderVisitor{ m_renderShape }, render.texture);
		m_window.draw(m_renderShape, m_renderState);
	});
}
