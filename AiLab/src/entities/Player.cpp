#include "stdafx.h"
#include "Player.h"
#include "components/Location.h"
#include "components/Motion.h"
#include "components/Render.h"


uint32_t app::ent::Player::create(app::Registry & registry)
{
	auto entity = registry.create();

	auto location = comp::Location();
	location.position = { 200.0f, 200.0f };
	location.angle = 0.0f;
	registry.assign<comp::Location>(entity, std::move(location));

	auto motion = comp::Motion();
	motion.velocity = { 0.0f, 0.0f };
	motion.angularSpeed = 0.0f;
	registry.assign<comp::Motion>(entity, std::move(motion));

	auto render = comp::Render();
	render.size = { 100.0f, 100.0f };
	render.texture = sf::Color{ 0u, 0u, 255u, 255u };
	registry.assign<comp::Render>(entity, std::move(render));

	return entity;
}
