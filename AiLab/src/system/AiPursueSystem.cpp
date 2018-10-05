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
	if (!m_player.has_value()) { return; }
	auto view = m_registry.view<comp::Location, comp::Motion, comp::AiPursue>();

	view.each([&](app::Entity const entity, comp::Location & location, comp::Motion & motion, comp::AiPursue & aiPursue)
	{

	});
}
