#include "stdafx.h"
#include "Enemy.h"
#include "components/Location.h"
#include "components/Dimensions.h"
#include "components/Motion.h"
#include "components/Collision.h"
#include "components/Render.h"

uint32_t app::ent::Enemy::create(app::Registry & registry)
{
	auto entity = registry.create();

	auto location = comp::Location();
	location.position = { 300.0f, 200.0f };
	location.angle = 0.0f;
	registry.assign<comp::Location>(entity, std::move(location));

	auto dimensions = comp::Dimensions();
	dimensions.size = { 50.0f, 50.0f };
	dimensions.origin = dimensions.size / 2.0f;
	registry.assign<comp::Dimensions>(entity, std::move(dimensions));

	auto motion = comp::Motion();
	motion.speed = 0.5f;
	motion.angularSpeed = 0.0f;
	registry.assign<comp::Motion>(entity, std::move(motion));

	registry.assign<comp::Collision>(entity);

	auto render = comp::Render();
	sf::Texture texture;
	texture.loadFromFile("./assets/enemy.png")
		? render.texture = std::make_shared<sf::Texture>(std::move(texture))
		: render.texture = sf::Color{ 255u, 0u, 0u, 255u };
	registry.assign<comp::Render>(entity, std::move(render));

	return std::move(entity);
}
