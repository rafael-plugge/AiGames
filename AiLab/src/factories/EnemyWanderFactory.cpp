#include "stdafx.h"
#include "EnemyWanderFactory.h"

#include "components/Location.h"
#include "components/Dimensions.h"
#include "components/Motion.h"
#include "components/Collision.h"
#include "components/Render.h"
#include "components/AiWander.h"

app::fact::EnemyWanderFactory::EnemyWanderFactory(app::Registry & registry)
	: BaseFactory(registry)
{
}

app::Entity app::fact::EnemyWanderFactory::create()
{
	app::Entity entity = m_registry.create();

	auto location = comp::Location();
	location.position = { 1200.0f, 700.0f };
	location.angle = -45.0f;
	m_registry.assign<comp::Location>(entity, std::move(location));

	auto dimensions = comp::Dimensions();
	dimensions.size = { 50.0f, 50.0f };
	dimensions.origin = dimensions.size / 2.0f;
	m_registry.assign<comp::Dimensions>(entity, std::move(dimensions));

	auto motion = comp::Motion();
	motion.speed = 0.5f;
	motion.angularSpeed = 0.0f;
	m_registry.assign<comp::Motion>(entity, std::move(motion));

	m_registry.assign<comp::Collision>(entity);

	auto render = comp::Render();
	sf::Texture texture;
	texture.loadFromFile("./assets/enemy.png")
		? render.texture = std::make_shared<sf::Texture>(std::move(texture))
		: render.texture = sf::Color::Yellow;
	m_registry.assign<comp::Render>(entity, std::move(render));

	auto aiWander = comp::AiWander();
	aiWander.maxMeander = 1.2f;
	m_registry.assign<comp::AiWander>(entity, std::move(aiWander));

	return entity;
}
