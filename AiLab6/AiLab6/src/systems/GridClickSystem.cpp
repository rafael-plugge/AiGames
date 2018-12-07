#include "stdafx.h"
#include "GridClickSystem.h"

// Utilities
#include "utilities/CollisionChecking.h"

// Components
#include "components/Location.h"
#include "components/Dimensions.h"
#include "components/Grid.h"

app::sys::GridClickSystem::GridClickSystem(app::inp::Mousehandler & mouseHandler, app::inp::Keyhandler & keyHandler)
	: BaseSystem()
	, m_mouseHandler(mouseHandler)
	, m_keyHandler(keyHandler)
{
}

void app::sys::GridClickSystem::update(app::time::nanoseconds const & dt)
{
	auto const & startKeyDown = m_keyHandler.isKeyDown(sf::Keyboard::Key::S);
	auto const & goalKeyDown = m_keyHandler.isKeyDown(sf::Keyboard::Key::G);
	auto const & wallKeyDown = m_keyHandler.isKeyDown(sf::Keyboard::Key::W);
	auto const & resetKeyDown = m_keyHandler.isKeyPressed(sf::Keyboard::R);
	auto const & mouseDown = m_mouseHandler.isButtonDown(sf::Mouse::Button::Left);
	if (!(mouseDown || startKeyDown || goalKeyDown || wallKeyDown || resetKeyDown)) { return; }
	auto const & mousePosition = math::Vector2f{
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
				if (resetKeyDown)
				{
					grid.start.reset();
					grid.goal.reset();
					grid.walls.clear();
				}
				else if (util::CollisionChecking::pointToRectangle(mousePosition, position, cellDimensions))
				{
					if (startKeyDown) { grid.start = { i, j }; }
					if (goalKeyDown) { grid.goal = { i, j }; }
					if (wallKeyDown)
					{
						if (std::find_if(grid.walls.begin(), grid.walls.end(), [&](auto const & a) { return a.at(0) == i && a.at(1) == j; }) == grid.walls.end())
						{
							grid.walls.push_back({ i, j });
						}
					}
				}
			}
		}
	});
}
