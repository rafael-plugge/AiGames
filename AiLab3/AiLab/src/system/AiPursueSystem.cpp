#include "stdafx.h"
#include "AiPursueSystem.h"

// Components
#include "components/Player.h"
#include "components/Location.h"
#include "components/Motion.h"
#include "components/AiPursue.h"

#include "utilities/Math.h"

app::sys::AiPursueSystem::AiPursueSystem(app::Registry & registry)
	: BaseSystem(registry)
{
	m_registry.construction<comp::Player>(entt::tag_t()).connect<sys::AiPursueSystem, &sys::AiPursueSystem::player>(this);
}

app::sys::AiPursueSystem::~AiPursueSystem()
{
	m_registry.construction<comp::Player>(entt::tag_t()).disconnect<sys::AiPursueSystem, &sys::AiPursueSystem::player>(this);
}

void app::sys::AiPursueSystem::player(app::Registry & registry, app::Entity entity)
{
	m_player = m_registry.valid(entity)
		? entity
		: throw std::exception("Tried to assign invalid entity in AiPursueSystem::player");
}

void app::sys::AiPursueSystem::update(app::seconds const & dt)
{
	if (!m_player.has_value() || !m_registry.valid(m_player.value())) { return; }
	auto[playerLocation, playerMotion] = m_registry.get<comp::Location, comp::Motion>(m_player.value());

	m_registry.view<comp::Location, comp::Motion, comp::AiPursue>()
		.each([&](app::Entity const entity, app::comp::Location & location, comp::Motion & motion, comp::AiPursue & aiPursue)
	{
		const float angleRad = app::Math::degToRad(playerLocation.angle);
		const sf::Vector2f playerVelocity = sf::Vector2f{ std::sin(angleRad), -std::cos(angleRad) } * playerMotion.speed;
		const sf::Vector2f futurePlayerPosition = playerLocation.position + (playerVelocity * static_cast<float>(dt.count() * aiPursue.predictTimeSteps));
		const auto angle = app::Math::radToDeg(std::atan2f(-(location.position.x - futurePlayerPosition.x), location.position.y - futurePlayerPosition.y));
		motion.angularSpeed = app::Math::angleBetween(angle, location.angle);
	});
}
