#include "stdafx.h"
#include "EnemyArriveFactory.h"

app::fact::EnemyArriveFactory::EnemyArriveFactory(app::Registry & registry, comp::Location location, comp::Dimensions dimensions, comp::Motion motion,
	comp::Collision collision, comp::ConeVision coneVision, comp::Render render, comp::AiSeek aiSeek, comp::AiArrive aiArrive
)
	: BaseFactory(registry)
	, m_location(location)
	, m_dimensions(dimensions)
	, m_motion(motion)
	, m_collision(collision)
	, m_coneVision(coneVision)
	, m_render(render)
	, m_aiSeek(aiSeek)
	, m_aiArrive(aiArrive)
{
}

app::Entity app::fact::EnemyArriveFactory::create()
{
	app::Entity entity = m_registry.create();

	m_registry.assign<decltype(m_location)>(entity, m_location);
	m_registry.assign<decltype(m_dimensions)>(entity, m_dimensions);
	m_registry.assign<decltype(m_motion)>(entity, m_motion);
	m_registry.assign<decltype(m_collision)>(entity, m_collision);
	m_registry.assign<decltype(m_coneVision)>(entity, m_coneVision);
	m_registry.assign<decltype(m_render)>(entity, m_render);
	m_registry.assign<decltype(m_aiSeek)>(entity, m_aiSeek);
	m_registry.assign<decltype(m_aiArrive)>(entity, m_aiArrive);

	return entity;
}
