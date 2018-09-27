#include "stdafx.h"
#include "AiSeekSystem.h"

#include "components/Player.h"
#include "components/Location.h"
#include "components/Motion.h"
#include "components/AiSeek.h"

#include "utilities/Math.h"

app::sys::AiSeekSystem::AiSeekSystem(app::Registry & registry)
	: BaseSystem(registry)
	, m_player(0)
	, m_maxSpeed(0.5f)
{
	m_registry.prepare<comp::Location, comp::Motion, comp::AiSeek>();
	m_registry.construction<comp::Player>(entt::tag_t()).connect<sys::AiSeekSystem, &sys::AiSeekSystem::player>(this);
}

void app::sys::AiSeekSystem::player(app::Registry & registry, app::Entity entity)
{
	if (!registry.valid(entity)) { throw std::exception("Tried to assign invalid entity in AiSeekSystem::player"); }
	m_player = entity;
}

void app::sys::AiSeekSystem::update(app::seconds const & dt)
{
	if (!m_registry.valid(m_player)) { return; }
	auto [playerLocation, playerMotion] = m_registry.get<comp::Location, comp::Motion>(m_player);

	auto view = m_registry.view<comp::Location, comp::Motion, comp::AiSeek>(entt::persistent_t());
	view.each([&](app::Entity const & entity, comp::Location & location, comp::Motion & motion, comp::AiSeek & aiSeek)
	{
		motion.speed = m_maxSpeed;
		const auto angle = app::Math::radToDeg(std::atan2f(-(location.position.x - playerLocation.position.x), location.position.y - playerLocation.position.y));
		motion.angularSpeed = app::Math::angleBetween(angle, location.angle) * static_cast<float>(dt.count());
	});
}
