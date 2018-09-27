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
	, m_maxSpeed(0.2f)
{
}

void app::sys::AiFleeSystem::player(app::Registry & registry, app::Entity entity)
{
	if (!registry.valid(entity)) { throw std::exception("Tried to assign invalid entity in AiFleeSystem::player"); }
	m_player = entity;
}

void app::sys::AiFleeSystem::update(app::seconds const & dt)
{
	if (!m_registry.valid(m_player)) { return; }
	auto[playerLocation, playerMotion] = m_registry.get<comp::Location, comp::Motion>(m_player);

	auto view = m_registry.view<comp::Location, comp::Motion, comp::AiFlee>();
	view.each([&](app::Entity const & entity, comp::Location & location, comp::Motion & motion, comp::AiFlee & aiFlee)
	{
		motion.speed = m_maxSpeed;
		const auto angle = -app::Math::radToDeg(std::atan2f(-(location.position.x - playerLocation.position.x), location.position.y - playerLocation.position.y));
		motion.angularSpeed = app::Math::angleBetween(angle, location.angle) * static_cast<float>(dt.count());
	});
}
