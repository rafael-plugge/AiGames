#include "stdafx.h"
#include "AiWanderSystem.h"

#include "components/Player.h"
#include "components/Location.h"
#include "components/Motion.h"
#include "components/Collision.h"
#include "components/AiWander.h"

#include "utilities/Math.h"

app::sys::AiWanderSystem::AiWanderSystem(app::Registry & registry)
	: BaseSystem(registry)
	, m_maxOffset(1.0f)
	, m_minOffset(-1.0f)
	, m_stepOffset(0.004f)
	, m_randomEngine()
	, m_distribution(0.0f, 100.0f)
	, m_offset(0.0f)
	, m_increase(true)
{
	m_registry.construction<comp::Player>(entt::tag_t()).connect<sys::AiWanderSystem, &sys::AiWanderSystem::player>(this);
}

app::sys::AiWanderSystem::~AiWanderSystem()
{
	m_registry.construction<comp::Player>(entt::tag_t()).disconnect<sys::AiWanderSystem, &sys::AiWanderSystem::player>(this);
}

void app::sys::AiWanderSystem::player(app::Registry & registry, app::Entity entity)
{
	m_player = registry.valid(entity)
		? entity
		: throw std::exception("Tried to assign invalid entity in AiSeekSystem::player");
}

void app::sys::AiWanderSystem::update(app::seconds const & dt)
{
	if (!m_player.has_value() || !m_registry.valid(m_player.value())) { return; }
	auto[playerLocation, playerMotion] = m_registry.get<comp::Location, comp::Motion>(m_player.value());

	m_offset += m_increase ? m_stepOffset : -m_stepOffset;
	if (m_offset > m_maxOffset || m_offset < m_minOffset) { m_increase = !m_increase; m_offset += m_increase ? m_stepOffset : -m_stepOffset; }

	auto view = m_registry.view<comp::Location, comp::Motion, comp::AiWander>();
	view.each([&](app::Entity const & entity, comp::Location & location, comp::Motion & motion, comp::AiWander & aiWander)
	{
		const auto angle = app::Math::radToDeg(std::atan2f(-(location.position.x - playerLocation.position.x), location.position.y - playerLocation.position.y));
		const auto deltaAngle = app::Math::angleBetween(angle, location.angle) * static_cast<float>(dt.count());
		motion.angularSpeed = deltaAngle + (aiWander.maxMeander * m_offset);
		// Cap turning speed
		//motion.angularSpeed = app::Math::cap(deltaAngle, aiWander.maxMeander, -aiWander.maxMeander);
	});
}

float app::sys::AiWanderSystem::generateRandomPercentage()
{
	return m_distribution(m_randomEngine) * (1.0f / 100.0f);
}
