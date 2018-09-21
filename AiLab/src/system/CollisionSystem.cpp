#include "stdafx.h"
#include "CollisionSystem.h"
#include "components/Location.h"
#include "components/Dimensions.h"
#include "components/Collision.h"

app::sys::CollisionSystem::CollisionSystem(app::Registry & registry, sf::Vector2f const & windowSize)
	: BaseSystem(registry)
	, m_windowSize(windowSize)
	, m_boundary(10.0f)
{
}

void app::sys::CollisionSystem::update(app::seconds const & dt)
{
	auto view = m_registry.view<comp::Location, comp::Dimensions, comp::Collision>();
	view.each([this](auto entity, comp::Location & location, comp::Dimensions & dimensions, comp::Collision const & collision) -> void
	{
		auto topLeft = location.position - dimensions.origin;

		if (topLeft.x + dimensions.size.x < -m_boundary) { topLeft.x = m_windowSize.x + m_boundary; }
		if (topLeft.x > m_windowSize.x + m_boundary) { topLeft.x = -m_boundary - dimensions.size.x; }
		if (topLeft.y + dimensions.size.y < -m_boundary) { topLeft.y = m_windowSize.y + m_boundary; }
		if (topLeft.y > m_windowSize.y + m_boundary) { topLeft.y = -m_boundary - dimensions.size.y; }

		location.position = topLeft + dimensions.origin;
	});
}
