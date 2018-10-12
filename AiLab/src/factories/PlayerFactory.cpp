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
#include "components/Label.h"

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
	dimensions.size = { 100.0f, 100.0f };
	dimensions.origin = dimensions.size / 2.0f;
	m_registry.assign<comp::Dimensions>(entity, std::move(dimensions));

	auto motion = comp::Motion();
	motion.speed = 0.2f;
	motion.angularSpeed = 0.0f;
	m_registry.assign<comp::Motion>(entity, std::move(motion));

	m_registry.assign<comp::MotionInput>(entity);

	m_registry.assign<comp::Collision>(entity);

	auto render = comp::Render();
	std::shared_ptr<sf::Texture> texture = std::make_shared<sf::Texture>();
	if (texture->loadFromFile("./assets/spaceship.png")) { render.texture = texture; }
	else { render.texture = sf::Color{ 0u, 0u, 255u, 255u }; }
	m_registry.assign<comp::Render>(entity, std::move(render));

	auto label = comp::Label();
	std::shared_ptr<sf::Font> font = std::make_shared<sf::Font>();
	if (font->loadFromFile("./assets/calibri.ttf")) { label.font = font; }
	label.color = sf::Color::White;
	label.offset = { 0.0f, -100.0f };
	label.text = "Player";

	return entity;
}
