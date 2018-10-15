#include "stdafx.h"
#include "EnemyWanderFactory.h"

app::fact::EnemyWanderFactory::EnemyWanderFactory(app::Registry & registry, comp::Location location, comp::Dimensions dimensions, comp::Motion motion,
	comp::Collision collision, comp::ConeVision coneVision, comp::Render render, comp::AiWander aiWander
)
	: BaseFactory(registry)
	, m_location(location)
	, m_dimensions(dimensions)
	, m_motion(motion)
	, m_collision(collision)
	, m_coneVision(coneVision)
	, m_render(render)
	, m_aiWander(aiWander)
{
}

app::Entity app::fact::EnemyWanderFactory::create()
{
	app::Entity entity = m_registry.create();

	m_registry.assign<decltype(m_location)>(entity, m_location);
	m_registry.assign<decltype(m_dimensions)>(entity, m_dimensions);
	m_registry.assign<decltype(m_motion)>(entity, m_motion);
	m_registry.assign<decltype(m_collision)>(entity, m_collision);
	m_registry.assign<decltype(m_coneVision)>(entity, m_coneVision);
	m_registry.assign<decltype(m_render)>(entity, m_render);
	m_registry.assign<decltype(m_aiWander)>(entity, m_aiWander);

	return entity;
}
