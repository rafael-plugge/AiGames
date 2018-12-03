#include "stdafx.h"
#include "RenderRectSystem.h"

// Components
#include "components/Location.h"
#include "components/Dimensions.h"
#include "components/RenderRect.h"

app::sys::RenderRectSystem::RenderRectSystem(gra::SfWindow & window)
	: BaseSystem()
	, m_window(window)
	, m_renderShape()
	, m_renderState(sf::RenderStates::Default)
{
}

void app::sys::RenderRectSystem::update(app::time::nanoseconds const & dt)
{
	m_registry.view<comp::Location, comp::Dimensions, comp::RenderRect>()
		.each([this, &dt](app::Entity const entity, comp::Location & location, comp::Dimensions & dimensions, comp::RenderRect & renderRect) -> void
	{
		m_renderShape.setPosition(location.position);
		m_renderShape.setRotation(location.orientation);
		std::visit(app::vis::RenderRectVisitor{ m_renderShape }, renderRect.fill);
		m_renderShape.setOutlineColor(renderRect.stroke.value_or(sf::Color::White));
		m_renderShape.setOutlineThickness(renderRect.thickness.value_or(0.0f));
		m_renderShape.setSize(dimensions.size);
		m_renderShape.setOrigin(dimensions.origin);
		m_window.draw(m_renderShape, m_renderState);
	});
}
