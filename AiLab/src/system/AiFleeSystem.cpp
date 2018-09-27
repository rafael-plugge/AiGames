#include "stdafx.h"
#include "AiFleeSystem.h"

// Components
#include "components/Location.h"
#include "components/Motion.h"
#include "components/AiFlee.h"

#include "utilities/Math.h"

app::sys::AiFleeSystem::AiFleeSystem(app::Registry & registry)
	: BaseSystem(registry)
	, m_player(0)
{
}

void app::sys::AiFleeSystem::player(app::Registry & registry, app::Entity entity)
{
	m_player = registry.valid(entity)
		? entity
		: throw std::exception("Tried to assign invalid entity in AiFleeSystem::player");
}

void app::sys::AiFleeSystem::update(app::seconds const & dt)
{
	if (!m_registry.valid(m_player)) { return; }
	auto[playerLocation, playerMotion] = m_registry.get<comp::Location, comp::Motion>(m_player);

	auto view = m_registry.view<comp::Location, comp::Motion, comp::AiFlee>();
	view.each([&](app::Entity const & entity, comp::Location & location, comp::Motion & motion, comp::AiFlee & aiFlee)
	{
		const auto angle = app::Math::radToDeg(std::atan2f(-(playerLocation.position.x - location.position.x), playerLocation.position.y - location.position.y));
		motion.angularSpeed = app::Math::angleBetween(angle, location.angle) * static_cast<float>(dt.count());
	});
}
