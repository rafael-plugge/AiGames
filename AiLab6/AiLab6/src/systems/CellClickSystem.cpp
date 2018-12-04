#include "stdafx.h"
#include "CellClickSystem.h"

app::sys::CellClickSystem::CellClickSystem(app::inp::Mousehandler const & mouseHandler)
	: BaseSystem()
	, m_mouseHandler(mouseHandler)
	, m_callbacks()
{
	m_registry.prepare<comp::Location, comp::Dimensions, comp::Cell>();
}

app::sys::CellClickSystem::CellClickSystem(app::inp::Mousehandler const & mouseHandler, VectorCallback::value_type const & callback)
	: BaseSystem()
	, m_mouseHandler(mouseHandler)
	, m_callbacks(1, callback)
{
	m_registry.prepare<comp::Location, comp::Dimensions, comp::Cell>();
}

app::sys::CellClickSystem::CellClickSystem(app::inp::Mousehandler const & mouseHandler, VectorCallback  const & callbacks)
	: BaseSystem()
	, m_mouseHandler(mouseHandler)
	, m_callbacks(std::move(callbacks))
{
	m_registry.prepare<comp::Location, comp::Dimensions, comp::Cell>();
}

void app::sys::CellClickSystem::update(app::time::nanoseconds const & dt)
{
	constexpr auto MOUSE_BUTTON = sf::Mouse::Button::Left;
	if (!m_mouseHandler.isButtonDown(MOUSE_BUTTON)) { return; }

	m_registry.view<comp::Location, comp::Dimensions, comp::Cell>(entt::persistent_t{})
		.each([&, this](app::Entity const entity, comp::Location & location, comp::Dimensions & dimensions, comp::Cell & cell) -> void
	{
		auto const & mousePos = m_mouseHandler.getPosition();
		if (this->rectCollision(mousePos, location, dimensions))
		{
			app::Console::writeLine({ "clicked: [ entity(", std::to_string(entity), "), mouse(", mousePos, ") ]" });
			if (!m_mouseHandler.isButtonPressed(MOUSE_BUTTON)) { return; }

			std::for_each(m_callbacks.begin(), m_callbacks.end(),
				[&](VectorCallback::value_type const & callback) { callback(entity, location, dimensions, cell); });
			return;
		}
	});
}

constexpr bool app::sys::CellClickSystem::rectCollision(math::Vector2i const & pos, comp::Location const & location, comp::Dimensions const & dimensions)
{
	return (location.position.x < pos.x  && pos.x < (location.position.x + dimensions.size.x))
		&& (location.position.y < pos.y && pos.y < (location.position.y + dimensions.size.y));
}
