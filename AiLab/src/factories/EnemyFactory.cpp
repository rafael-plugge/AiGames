#include "stdafx.h"
#include "EnemyFactory.h"

// Components
#include "components/Location.h"
#include "components/Dimensions.h"
#include "components/Motion.h"
#include "components/Collision.h"
#include "components/Render.h"

app::fact::EnemyFactory::EnemyFactory(app::Registry & registry)
	: BaseFactory(registry)
	, m_filePath("")
{
}

app::fact::EnemyFactory::EnemyFactory(app::Registry & registry, std::string const & filePath)
	: BaseFactory(registry)
	, m_filePath(filePath)
{
}

app::Entity app::fact::EnemyFactory::create()
{
	return this->create(m_filePath);
}

app::Entity app::fact::EnemyFactory::create(std::string const & filePath)
{
	app::Entity entity = m_registry.create();

	auto location = comp::Location();
	location.position = { 300.0f, 200.0f };
	location.angle = 0.0f;
	m_registry.assign<comp::Location>(entity, std::move(location));

	auto dimensions = comp::Dimensions();
	dimensions.size = { 10.0f, 10.0f };
	dimensions.origin = dimensions.size / 2.0f;
	m_registry.assign<comp::Dimensions>(entity, std::move(dimensions));

	auto motion = comp::Motion();
	motion.speed = 0.5f;
	motion.angularSpeed = 0.0f;
	m_registry.assign<comp::Motion>(entity, std::move(motion));

	m_registry.assign<comp::Collision>(entity);

	auto render = comp::Render();
	sf::Texture texture;
	(filePath.length() > 0 && texture.loadFromFile(filePath))
		? render.texture = std::make_shared<sf::Texture>(std::move(texture))
		: render.texture = sf::Color{ 255u, 0u, 0u, 255u };
	m_registry.assign<comp::Render>(entity, std::move(render));

	return entity;
}