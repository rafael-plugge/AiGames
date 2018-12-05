#include "stdafx.h"
#include "CellClickSystem.h"

app::sys::CellClickSystem::CellClickSystem(app::inp::Mousehandler const & mouseHandler)
	: BaseSystem()
	, m_mouseHandler(mouseHandler)
	, m_callbacks()
	, m_clickedColor(240u, 30, 30, 255u)
	, m_unclickedColor(30u, 30u, 240u, 255u)
{
	m_registry.prepare<comp::Location, comp::Dimensions, comp::Cell, comp::RenderRect>();
}

app::sys::CellClickSystem::CellClickSystem(app::inp::Mousehandler const & mouseHandler, VectorCallback::value_type const & callback)
	: BaseSystem()
	, m_mouseHandler(mouseHandler)
	, m_callbacks(1, callback)
	, m_clickedColor(240u, 30, 30, 255u)
	, m_unclickedColor(30u, 30u, 240u, 255u)
{
	m_registry.prepare<comp::Location, comp::Dimensions, comp::Cell, comp::RenderRect>();
}

app::sys::CellClickSystem::CellClickSystem(app::inp::Mousehandler const & mouseHandler, VectorCallback  const & callbacks)
	: BaseSystem()
	, m_mouseHandler(mouseHandler)
	, m_callbacks(std::move(callbacks))
	, m_clickedColor(240u, 30, 30, 255u)
	, m_unclickedColor(30u, 30u, 240u, 255u)
{
	m_registry.prepare<comp::Location, comp::Dimensions, comp::Cell, comp::RenderRect>();
}

void app::sys::CellClickSystem::update(app::time::nanoseconds const & dt)
{
	if (!m_mouseHandler.isButtonDown(sf::Mouse::Button::Left)) { return; }

	auto const & mousePos = m_mouseHandler.getPosition();
	m_registry.view<comp::Location, comp::Dimensions, comp::Cell, comp::RenderRect>(entt::persistent_t{})
		.each([&, this](app::Entity const entity, comp::Location & location, comp::Dimensions & dimensions, comp::Cell & cell, comp::RenderRect & renderRect) -> void
	{
		cell.clicked = this->rectCollision(mousePos, location, dimensions);
		if (cell.clicked)
		{
			app::Console::writeLine({ "clicked: [ entity(", std::to_string(entity), "), mouse(", mousePos, ") ]" });
			renderRect.fill = m_clickedColor;
			
			for (VectorCallback::value_type const & callback : m_callbacks) { callback(entity, location, dimensions, cell, renderRect); }
			return;
		}
		renderRect.fill = m_unclickedColor;
	});
}

constexpr bool app::sys::CellClickSystem::rectCollision(math::Vector2i const & pos, comp::Location const & location, comp::Dimensions const & dimensions)
{
	return (location.position.x < pos.x  && pos.x < (location.position.x + dimensions.size.x))
		&& (location.position.y < pos.y && pos.y < (location.position.y + dimensions.size.y));
}
