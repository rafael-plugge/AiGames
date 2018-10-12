#include "stdafx.h"
#include "EnemyArriveFactory.h"

#include "components/Location.h"
#include "components/Dimensions.h"
#include "components/Motion.h"
#include "components/Collision.h"
#include "components/Render.h"
#include "components/AiSeek.h"
#include "components/AiArrive.h"

app::fact::EnemyArriveFactory::EnemyArriveFactory(app::Registry & registry, sf::Vector2f position, float speed, float radius)
	: BaseFactory(registry)
	, m_position(position)
	, m_radius(radius)
	, m_speed(speed)
{
}

app::Entity app::fact::EnemyArriveFactory::create()
{
	app::Entity entity = m_registry.create();

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

	return entity;
}
