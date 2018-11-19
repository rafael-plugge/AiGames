#include "stdafx.h"
#include "EnemyFormationFactory.h"

#include "components/Location.h"
#include "components/Dimensions.h"
#include "components/Motion.h"
#include "components/Collision.h"
#include "components/Render.h"
#include "components/AiFormation.h"
#include "components/AiFormationLeader.h"

app::fact::EnemyFormationFactory::EnemyFormationFactory(app::Registry & registry)
	: BaseFactory(registry)
{
}

app::Entity app::fact::EnemyFormationFactory::create()
{
	app::Entity const leader = this->createLeader();

	app::Entity entity = m_registry.create();

	auto location = comp::Location();
	location.position = { 400.0f, 300.0f };
	location.angle = 0.0f;
	m_registry.assign<decltype(location)>(entity, std::move(location));

	auto dimensions = comp::Dimensions();
	dimensions.size = { 70.0f, 70.0f };
	dimensions.origin = dimensions.size / 2.0f;
	m_registry.assign<decltype(dimensions)>(entity, std::move(dimensions));

	auto motion = comp::Motion();
	motion.speed = 2.3f;
	motion.angularSpeed = 1.0f;
	m_registry.assign<decltype(motion)>(entity, std::move(motion));

	auto collision = comp::Collision();
	m_registry.assign<decltype(collision)>(entity, std::move(collision));

	auto render = comp::Render();
	sf::Texture texture;
	texture.loadFromFile("./assets/enemy.png")
		? render.texture = std::make_shared<sf::Texture>(std::move(texture))
		: render.texture = sf::Color::White;
	m_registry.assign<decltype(render)>(entity, std::move(render));

	auto aiFormation = comp::AiFormation();
	aiFormation.leader = leader;
	m_registry.assign<decltype(aiFormation)>(entity, std::move(aiFormation));

	return entity;
}

app::Entity app::fact::EnemyFormationFactory::createLeader()
{
	app::Entity entity = m_registry.create();

	auto location = comp::Location();
	location.position = { 800.0f, 450.0f };
	location.angle = 0.0f;
	m_registry.assign<decltype(location)>(entity, std::move(location));

	auto dimensions = comp::Dimensions();
	dimensions.size = { 70.0f, 70.0f };
	dimensions.origin = dimensions.size / 2.0f;
	m_registry.assign<decltype(dimensions)>(entity, std::move(dimensions));

	auto motion = comp::Motion();
	motion.speed = 2.3f;
	motion.angularSpeed = 1.0f;
	m_registry.assign<decltype(motion)>(entity, std::move(motion));

	auto collision = comp::Collision();
	m_registry.assign<decltype(collision)>(entity, std::move(collision));

	auto render = comp::Render();
	sf::Texture texture;
	texture.loadFromFile("./assets/enemy.png")
		? render.texture = std::make_shared<sf::Texture>(std::move(texture))
		: render.texture = sf::Color::Magenta;
	m_registry.assign<decltype(render)>(entity, std::move(render));

	auto aiFormationLeader = comp::AiFormationLeader();
	m_registry.assign<decltype(aiFormationLeader)>(entity, std::move(aiFormationLeader));

	return entity;
}
