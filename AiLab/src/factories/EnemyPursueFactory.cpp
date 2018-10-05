#include "stdafx.h"
#include "EnemyPursueFactory.h"

#include "components/Location.h"
#include "components/Dimensions.h"
#include "components/Motion.h"
#include "components/Collision.h"
#include "components/Render.h"
#include "components/AiPursue.h"

app::fact::EnemyPursueFactory::EnemyPursueFactory(app::Registry & registry)
	: BaseFactory(registry)
{
}

app::Entity app::fact::EnemyPursueFactory::create()
{
	app::Entity entity = m_registry.create();

	auto location = comp::Location();
	location.position = { 900.0f, 300.0f };
	location.angle = 0.0f;
	m_registry.assign<decltype(location)>(entity, std::move(location));

	auto dimensions = comp::Dimensions();
	dimensions.size = { 120.0f, 120.0f };
	dimensions.origin = dimensions.size / 2.0f;
	m_registry.assign<decltype(dimensions)>(entity, std::move(dimensions));

	auto motion = comp::Motion();
	motion.speed = 0.0f;
	motion.angularSpeed = 1.0f;
	m_registry.assign<decltype(motion)>(entity, std::move(motion));

	m_registry.assign<comp::Collision>(entity);

	auto render = comp::Render();
	sf::Texture texture;
	texture.loadFromFile("./assets/enemy.png")
		? render.texture = std::make_shared<sf::Texture>(std::move(texture))
		: render.texture = sf::Color::Cyan;
	m_registry.assign<decltype(render)>(entity, std::move(render));

	m_registry.assign<comp::AiPursue>(entity);

	return entity;
}
