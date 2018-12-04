#include "stdafx.h"
#include "RenderGridSystem.h"

// Components
#include "components/Location.h"
#include "components/Dimensions.h"
#include "components/RenderGrid.h"

app::sys::RenderGridSystem::RenderGridSystem(app::gra::SfWindow & window)
	: BaseSystem()
	, m_window(window)
	, m_renderTarget()
	, m_renderShape()
	, m_renderStates(sf::RenderStates::Default)
{
	m_renderShape.setFillColor(sf::Color::Transparent);
	m_registry.prepare<comp::Location, comp::Dimensions, comp::RenderGrid>();
}

void app::sys::RenderGridSystem::update(app::time::nanoseconds const & dt)
{
	m_registry.view<comp::Location, comp::Dimensions, comp::RenderGrid>(entt::persistent_t{})
		.each([this, &dt](app::Entity const entity, comp::Location & location, comp::Dimensions & dimensions, comp::RenderGrid & renderGrid) -> void
	{
		m_renderShape.setRotation(location.orientation);
		m_renderShape.setOutlineColor(renderGrid.stroke.value_or(sf::Color::White));
		m_renderShape.setOutlineThickness(renderGrid.thickness.value_or(0.0f));
		const auto & cellSize = math::Vector2f{ dimensions.size.x / static_cast<float>(renderGrid.size.x), dimensions.size.y / static_cast<float>(renderGrid.size.y) };
		m_renderShape.setSize(cellSize);
		for (float x = 0.0f; x < dimensions.size.x; x += cellSize.x)
		{
			for (float y = 0.0f; y < dimensions.size.y; y += cellSize.y)
			{
				m_renderShape.setPosition(location.position.x + x, location.position.y + y);
				m_window.draw(m_renderShape, m_renderStates);
			}
		}
	});
}