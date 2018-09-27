#include "stdafx.h"
#include "PlayerFactory.h"

// Components
#include "components/Player.h"
#include "components/Location.h"
#include "components/Dimensions.h"
#include "components/Motion.h"
#include "components/MotionInput.h"
#include "components/Collision.h"
#include "components/Render.h"

app::fact::PlayerFactory::PlayerFactory(app::Registry & registry)
	: BaseFactory(registry)
{
}

app::Entity app::fact::PlayerFactory::create()
{
	app::Entity entity = m_registry.create();

	m_registry.assign<comp::Player>(entt::tag_t(), entity);

	auto location = comp::Location();
	location.position = { 200.0f, 200.0f };
	location.angle = 0.0f;
	m_registry.assign<comp::Location>(entity, std::move(location));

	auto dimensions = comp::Dimensions();
	dimensions.size = { 200.0f, 200.0f };
	dimensions.origin = dimensions.size / 2.0f;
	m_registry.assign<comp::Dimensions>(entity, std::move(dimensions));

	auto motion = comp::Motion();
	motion.speed = 0.2f;
	motion.angularSpeed = 0.0f;
	m_registry.assign<comp::Motion>(entity, std::move(motion));

	auto motionInput = comp::MotionInput();
	motionInput.increaseSpeed = false;
	motionInput.decreaseSpeed = false;
	motionInput.rotateLeft = false;
	motionInput.rotateRight = false;
	m_registry.assign<comp::MotionInput>(entity, std::move(motionInput));

	m_registry.assign<comp::Collision>(entity);

	auto render = comp::Render();
	sf::Texture texture;
	texture.loadFromFile("./assets/spaceship.png")
		? render.texture = std::make_shared<sf::Texture>(std::move(texture))
		: render.texture = sf::Color{ 0u, 0u, 255u, 255u };
	m_registry.assign<comp::Render>(entity, std::move(render));

	return entity;
}
