#include "stdafx.h"
#include "EnemySeekFactory.h"

#include "components/Location.h"
#include "components/Dimensions.h"
#include "components/Motion.h"
#include "components/Collision.h"
#include "components/Render.h"
#include "components/AiSeek.h"

app::fact::EnemySeekFactory::EnemySeekFactory(app::Registry & registry)
	: BaseFactory(registry)
{
}

app::Entity app::fact::EnemySeekFactory::create()
{
	app::Entity entity = m_registry.create();

	auto location = comp::Location();
	location.position = { 1000.0f, 200.0f };
	location.angle = 0.0f;
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

	m_registry.assign<comp::AiSeek>(entity);

	return entity;
}
