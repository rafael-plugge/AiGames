#include "stdafx.h"
#include "EnemyArriveFactory.h"

app::fact::EnemyArriveFactory::EnemyArriveFactory(app::Registry & registry, comp::Location location, comp::Dimensions dimensions, comp::Motion motion,
	comp::Collision collision, comp::Render render, comp::AiSeek aiSeek, comp::AiArrive aiArrive
)
	: BaseFactory(registry)
	, m_location(location)
	, m_dimensions(dimensions)
	, m_motion(motion)
	, m_collision(collision)
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
	m_registry.assign<decltype(m_render)>(entity, m_render);
	m_registry.assign<decltype(m_aiSeek)>(entity, m_aiSeek);
	m_registry.assign<decltype(m_aiArrive)>(entity, m_aiArrive);

	/*
	auto location = comp::Location();
	location.position = m_position;
	location.angle = 0.0f;
	m_registry.assign<comp::Location>(entity, std::move(location));

	auto dimensions = comp::Dimensions();
	dimensions.size = { 50.0f, 50.0f };
	dimensions.origin = dimensions.size / 2.0f;
	m_registry.assign<comp::Dimensions>(entity, std::move(dimensions));

	auto motion = comp::Motion();
	motion.speed = m_speed;
	motion.angularSpeed = 0.0f;
	m_registry.assign<comp::Motion>(entity, std::move(motion));

	m_registry.assign<comp::Collision>(entity);

	auto render = comp::Render();
	sf::Texture texture;
	texture.loadFromFile("./assets/enemy.png")
		? render.texture = std::make_shared<sf::Texture>(std::move(texture))
		: render.texture = sf::Color::Yellow;
	m_registry.assign<comp::Render>(entity, std::move(render));

	m_registry.assign<comp::AiSeek>(entity);
	
	auto aiArrive = comp::AiArrive();
	aiArrive.radius = m_radius;
	aiArrive.brakeSpeed = 0.95f;
	aiArrive.chaseSpeed = 1.5f;
	m_registry.assign<comp::AiArrive>(entity, std::move(aiArrive));
	/**/

	return entity;
}
