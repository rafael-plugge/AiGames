#include "stdafx.h"
#include "GridClickSystem.h"

// Utilities
#include "utilities/CollisionChecking.h"

// Components
#include "components/Location.h"
#include "components/Dimensions.h"
#include "components/Grid.h"

app::sys::GridClickSystem::GridClickSystem(app::inp::Mousehandler & mouseHandler)
	: m_mouseHandler(mouseHandler)
{
}

void app::sys::GridClickSystem::update(app::time::nanoseconds const & dt)
{
	auto const & mousePosition = sf::Vector2f{
		static_cast<float>(m_mouseHandler.getPosition().x),
		static_cast<float>(m_mouseHandler.getPosition().y)
	};
	m_registry.view<comp::Location, comp::Dimensions, comp::Grid>()
		.each([&, this](app::Entity const entity, comp::Location & location, comp::Dimensions & dimensions, comp::Grid & grid) -> void
	{
		math::Vector2f const cellDimensions = {
			dimensions.size.x / static_cast<float>(grid.width),
			dimensions.size.y / static_cast<float>(grid.height)
		};
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
				block.setClicked(util::CollisionChecking::pointToRectangle(mousePosition, position, cellDimensions));
			}
		}
	});
}
