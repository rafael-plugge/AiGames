#include "stdafx.h"
#include "AiSeekSystem.h"

#include "components/Player.h"
#include "components/Location.h"
#include "components/Motion.h"
#include "components/AiSeek.h"

#include "utilities/Math.h"

app::sys::AiSeekSystem::AiSeekSystem(app::Registry & registry)
	: BaseSystem(registry)
	, m_player()
{
	m_registry.prepare<comp::Location, comp::Motion, comp::AiSeek>();
	m_registry.construction<comp::Player>(entt::tag_t()).connect<sys::AiSeekSystem, &sys::AiSeekSystem::player>(this);
}

app::sys::AiSeekSystem::~AiSeekSystem()
{
	m_registry.construction<comp::Player>(entt::tag_t()).disconnect<sys::AiSeekSystem, &sys::AiSeekSystem::player>(this);
}

void app::sys::AiSeekSystem::player(app::Registry & registry, app::Entity entity)
{
	m_player = registry.valid(entity)
		? entity
		: throw std::exception("Tried to assign invalid entity in AiSeekSystem::player");
}

void app::sys::AiSeekSystem::update(app::seconds const & dt)
{
	if (!m_player.has_value() || !m_registry.valid(m_player.value())) { return; }
	auto [playerLocation, playerMotion] = m_registry.get<comp::Location, comp::Motion>(m_player.value());
	sf::Vector2f const & playerPosition = playerLocation.position;

	auto view = m_registry.view<comp::Location, comp::Motion, comp::AiSeek>(entt::persistent_t());
	view.each([&](app::Entity const & entity, comp::Location & location, comp::Motion & motion, comp::AiSeek & aiSeek)
	{
		const auto angle = app::Math::radToDeg(std::atan2f(-(location.position.x - playerPosition.x), location.position.y - playerPosition.y));
		motion.angularSpeed = app::Math::angleBetween(angle, location.angle) * static_cast<float>(dt.count());
	});
}
