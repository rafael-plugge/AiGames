#include "stdafx.h"
#include "RenderGridSystem.h"

// Components
#include "components/Location.h"
#include "components/Dimensions.h"
#include "components/Grid.h"
#include "components/RenderGrid.h"

app::sys::RenderGridSystem::RenderGridSystem(app::gra::SfWindow & window)
	: BaseSystem()
	, m_window(window)
	, m_renderTarget()
	, m_renderShape()
	, m_renderStates(sf::RenderStates::Default)
	, m_clickedColor(255u, 0u, 0u, 255u)
{
	m_renderShape.setFillColor(sf::Color::Transparent);
	m_registry.prepare<comp::Location, comp::Dimensions, comp::Grid, comp::RenderGrid>();
}

void app::sys::RenderGridSystem::update(app::time::nanoseconds const & dt)
{
	m_registry.view<comp::Location, comp::Dimensions, comp::Grid, comp::RenderGrid>(entt::persistent_t{})
		.each([this, &dt](app::Entity const entity, comp::Location & location, comp::Dimensions & dimensions, comp::Grid & grid, comp::RenderGrid & renderGrid) -> void
	{
		m_renderShape.setRotation(location.orientation);
		m_renderShape.setOutlineColor(renderGrid.stroke.value_or(sf::Color::White));
		m_renderShape.setOutlineThickness(renderGrid.thickness.value_or(0.0f));
		math::Vector2f const cellDimensions = {
			dimensions.size.x / static_cast<float>(grid.width),
			dimensions.size.y / static_cast<float>(grid.height)
		};
		m_renderShape.setSize(cellDimensions);
		for (std::size_t i = 0; i < grid.blocks.size(); ++i)
		{
			auto & line = grid.blocks[i];
			for (std::size_t j = 0; j < line.size(); ++j)
			{
				auto & block = line[j];
				math::Vector2f const position = {
					location.position.x + (cellDimensions.x * j),
					location.position.y + (cellDimensions.y * i)
				};
				if (grid.start.has_value() && grid.start.value().at(0) == i && grid.start.value().at(1) == j)
				{
					m_renderShape.setFillColor(sf::Color::Green);
				}
				else if (grid.goal.has_value() && grid.goal.value().at(0) == i && grid.goal.value().at(1) == j)
				{
					m_renderShape.setFillColor(sf::Color::Red);
				}
				else if (std::find_if(grid.walls.begin(), grid.walls.end(), [&](auto const & a) { return a.at(0) == i && a.at(1) == j; }) != grid.walls.end())
				{
					m_renderShape.setFillColor(sf::Color::Blue);
				}
				else { m_renderShape.setFillColor(sf::Color::Transparent); }

				m_renderShape.setPosition(position);
				m_window.draw(m_renderShape, m_renderStates);
			}
		}
	});
}