#include "stdafx.h"
#include "AiArriveSystem.h"

// Components
#include "components/Player.h"
#include "components/Location.h"
#include "components/Motion.h"
#include "components/AiArrive.h"

#include "utilities/Math.h"

app::sys::AiArriveSystem::AiArriveSystem(app::Registry & registry)
	: BaseSystem(registry)
	, m_minimumSpeed(0.0001f)
{
	m_registry.construction<comp::Player>(entt::tag_t()).connect<sys::AiArriveSystem, &sys::AiArriveSystem::player>(this);
}

app::sys::AiArriveSystem::~AiArriveSystem()
{
	m_registry.construction<comp::Player>(entt::tag_t()).disconnect<sys::AiArriveSystem, &sys::AiArriveSystem::player>(this);
}

void app::sys::AiArriveSystem::player(app::Registry & registry, app::Entity entity)
{
	m_player = registry.valid(entity)
		? entity
		: throw std::exception("Tried to assign invalid entity in AiArrive::player");
}

void app::sys::AiArriveSystem::update(app::seconds const & dt)
{
	if (!m_player.has_value() || !m_registry.valid(m_player.value())) { return; }
	auto[playerLocation, playerMotion] = m_registry.get<comp::Location, comp::Motion>(m_player.value());

	auto view = m_registry.view<comp::Location, comp::Motion, comp::AiArrive>();
	view.each([&](app::Entity const & entity, comp::Location & location, comp::Motion & motion, comp::AiArrive & aiArrive)
	{
		if (app::Math::length<float>(location.position - playerLocation.position) < aiArrive.radius)
		{
			motion.speed *= aiArrive.brakeSpeed;
			if (motion.speed < m_minimumSpeed) { motion.speed = 0.0f; }
		}
		else
		{
			motion.speed += aiArrive.chaseSpeed * static_cast<float>(dt.count());
			if (motion.speed > aiArrive.chaseSpeed) { motion.speed = aiArrive.chaseSpeed; }
		}
	});
}
