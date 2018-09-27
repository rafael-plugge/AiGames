#include "stdafx.h"
#include "AiWanderSystem.h"

#include "components/Location.h"
#include "components/Dimensions.h"
#include "components/Collision.h"
#include "components/AiWander.h"

app::sys::AiWanderSystem::AiWanderSystem(app::Registry & registry)
	: BaseSystem(registry)
{
	m_registry.prepare<comp::Location, comp::Dimensions, comp::Collision, comp::AiWander>();
}

void app::sys::AiWanderSystem::update(app::seconds const & dt)
{
	auto view = m_registry.view<comp::Location, comp::Dimensions, comp::Collision, comp::AiWander>(entt::persistent_t());
	view.each([&dt](app::Entity const & entity, comp::Location & location, comp::Dimensions & dimensions, comp::Collision & collisions, comp::AiWander & aiWander)
	{
	});
}
