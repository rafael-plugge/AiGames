#include "stdafx.h"
#include "AiFormationSystem.h"

// components
#include "components/Location.h"
#include "components/Motion.h"
#include "components/AiFormation.h"
#include "components/AiFormationLeader.h"

app::sys::AiFormationSystem::AiFormationSystem(app::Registry & registry)
	: BaseSystem(registry)
{
}

void app::sys::AiFormationSystem::update(app::seconds const & dt)
{
	m_registry.view<comp::Location, comp::Motion, comp::AiFormation>()
		.each([&](app::Entity const entity, comp::Location & location, comp::Motion & motion, comp::AiFormation & aiFormation)
	{
		if (m_registry.valid(aiFormation.leader))
		{
			comp::Location & leaderLocation = m_registry.get<comp::Location>(aiFormation.leader);
			
		}
	});
}
