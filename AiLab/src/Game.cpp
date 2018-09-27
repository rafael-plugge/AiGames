#include "stdafx.h"
#include "Game.h"

// Systems
#include "system/MotionSystem.h"
#include "system/InputSystem.h"
#include "system/CollisionSystem.h"
#include "system/RenderSystem.h"

// Components
#include "components/Location.h"
#include "components/Motion.h"
#include "components/Render.h"
#include "components/MotionInput.h"
#include "components/Dimensions.h"
#include "components/Collision.h"

// Entities
#include "entities/Player.h"
#include "entities/Enemy.h"

const sf::Color app::Game::s_clearColor = { 0u, 0u, 0u, 255u };

app::Game::Game()
	: m_gameLoop()
	, m_window()
	, m_windowBuffer()
	, m_windowTitle()
	, m_event()
	, m_registry()
	, m_updateSystems()
	, m_renderSystems()
{
}

int app::Game::run()
{
	using clock = std::chrono::high_resolution_clock;
	clock::time_point deltaTimePoint = clock::now();
	clock::duration elapsedTime = clock::duration::zero();

	if (bool success = this->init(); !success) { return EXIT_FAILURE; }

	while (m_gameLoop)
	{
		this->pollEvents();
		elapsedTime += std::chrono::duration_cast<clock::duration>(clock::now() - deltaTimePoint);
		deltaTimePoint = clock::now();
		while (elapsedTime > s_updateStep)
		{
			this->update(s_updateStepSec);
			elapsedTime -= s_updateStep;
		}
		this->render();
	}

	m_window.close();
	return EXIT_SUCCESS;
}

bool app::Game::init()
{
	try
	{
		m_gameLoop = true;
		m_windowBuffer = sf::VideoMode(1366u, 768u, 32u);
		m_windowSize = sf::Vector2f{ static_cast<float>(m_windowBuffer.width), static_cast<float>(m_windowBuffer.height) };
		m_windowTitle = "Ai Games Lab";

		sf::ContextSettings settings = sf::ContextSettings();
		settings.antialiasingLevel = 32u;
		m_window.create(m_windowBuffer, m_windowTitle, sf::Style::Default);

		return createCompDependencies() && createSystems() && createEntities();
	}
	catch (const std::exception& e)
	{
		std::cout << "Error in Game::init() -> " << e.what() << std::endl;
		return false;
	}
}

bool app::Game::createCompDependencies()
{
	// comp::MotionInput is now dependant on comp::Motion
	entt::connect<comp::Motion>(m_registry.construction<comp::MotionInput>());
	entt::connect<comp::Location, comp::Dimensions>(m_registry.construction<comp::Render>());
	entt::connect<comp::Location, comp::Dimensions>(m_registry.construction<comp::Collision>());

	return true;
}

bool app::Game::createSystems()
{
	std::unique_ptr<sys::BaseSystem> uptrSystem = nullptr;
	m_updateSystems.reserve(3);
	m_renderSystems.reserve(1);
	
	uptrSystem = std::make_unique<sys::InputSystem>(sys::InputSystem(m_registry, m_keyHandler));
	m_updateSystems.push_back(std::move(uptrSystem));

	uptrSystem = std::make_unique<sys::MotionSystem>(sys::MotionSystem(m_registry));
	m_updateSystems.push_back(std::move(uptrSystem));

	uptrSystem = std::make_unique<sys::CollisionSystem>(sys::CollisionSystem(m_registry, m_windowSize));
	m_updateSystems.push_back(std::move(uptrSystem));

	uptrSystem = std::make_unique<sys::RenderSystem>(sys::RenderSystem(m_registry, m_window));
	m_renderSystems.push_back(std::move(uptrSystem));

	return true;
}

bool app::Game::createEntities()
{
	ent::Player::create(m_registry);
	ent::Enemy::create(m_registry);

	return true;
}

void app::Game::pollEvents()
{
	while (m_window.pollEvent(m_event))
	{
		switch (m_event.type)
		{
		case sf::Event::Closed:
			m_gameLoop = false;
			break;
		case sf::Event::KeyPressed:
			m_keyHandler.updateKey(m_event.key.code, true);
			break;
		case sf::Event::KeyReleased:
			m_keyHandler.updateKey(m_event.key.code, false);
			break;
		default:
			break;
		}
	}
}

void app::Game::update(app::seconds const & dt)
{
	for (auto & system : m_updateSystems)
	{
		system->update(dt);
	}
}

void app::Game::render()
{
	m_window.clear(s_clearColor);

	for (auto & system : m_renderSystems)
	{
		system->update(app::seconds::zero());
	}

	m_window.display();
}