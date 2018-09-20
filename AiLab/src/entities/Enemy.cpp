#include "stdafx.h"
#include "Enemy.h"
#include "components/Location.h"
#include "components/Motion.h"
#include "components/Render.h"

uint32_t app::ent::Enemy::create(app::Registry & registry)
{
	auto entity = registry.create();

	auto location = comp::Location();
	location.position = { 300.0f, 200.0f };
	location.angle = 0.0f;
	registry.assign<comp::Location>(entity, std::move(location));

	auto motion = comp::Motion();
	motion.velocity = { 4.0f * (1 / 60.0f), 0.0f };
	motion.angularSpeed = 0.0f;
	registry.assign<comp::Motion>(entity, std::move(motion));

	auto render = comp::Render();
	render.size = { 20.0f, 20.0f };
	render.texture = sf::Color{ 255u, 0u, 0u, 255u };
	registry.assign<comp::Render>(entity, std::move(render));

	return std::move(entity);
}
