#include "stdafx.h"
#include "ConeVisionSystem.h"

// components
#include "components/Player.h"
#include "components/Location.h"
#include "components/ConeVision.h"

#include "utilities/Math.h"

app::sys::ConeVisionSystem::ConeVisionSystem(app::Registry & registry)
	: BaseSystem(registry)
{
	m_registry.construction<comp::Player>(entt::tag_t())
		.connect<app::sys::ConeVisionSystem, &app::sys::ConeVisionSystem::player>(this);
}

app::sys::ConeVisionSystem::~ConeVisionSystem()
{
	m_registry.construction<comp::Player>(entt::tag_t())
		.disconnect<app::sys::ConeVisionSystem, &app::sys::ConeVisionSystem::player>(this);
}

void app::sys::ConeVisionSystem::player(app::Registry & registry, app::Entity entity)
{
	assert(registry.valid(entity));
	m_player = registry.valid(entity) ? entity : throw std::exception("tried to assign invalid entity in ConeVisionSystem::player");
}

void app::sys::ConeVisionSystem::update(app::seconds const & dt)
{
	if (!m_player.has_value()) { return; }

	auto & playerLocation = m_registry.get<comp::Location>(m_player.value());

	m_registry.view<comp::Location, comp::ConeVision>()
		.each([&](app::Entity const entity, comp::Location & location, comp::ConeVision & coneVision)
	{
		m_registry.view<comp::Location>()
			.each([&](app::Entity const tEntity, comp::Location & tLocation)
		{
			if (entity == tEntity) { return; }
			auto const tDirection = tLocation.position - location.position;
			if (app::Math::lengthSqr(tDirection) > coneVision.radius * coneVision.radius) { return; }
			auto const angle = app::Math::toAngle(tDirection);
			if (location.angle + coneVision.angle < angle || location.angle - coneVision.angle > angle) { return; }
			std::cout << "collision: " << entity << "->" << tEntity << std::endl;
		});
	});
}
