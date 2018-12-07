#include "stdafx.h"
#include "Game.h"

// Components
#include "components/Grid.h"
#include "components/RenderGrid.h"

// Systems
#include "systems/CellClickSystem.h"
#include "systems/GridClickSystem.h"
#include "systems/RenderRectSystem.h"
#include "systems/RenderGridSystem.h"

// Factories
#include "factories/EntityJsonFactory.h"
#include "factories/CellsFactory.h"
#include "factories/GridFactory.h"

app::Game::Game()
	: m_window(nullptr)
	, m_registry(app::Reg::get())
	, m_keyHandler()
	, m_mouseHandler()
	, m_updateSystems()
	, m_renderSystems()
{
}

app::Game::~Game()
{
}

int app::Game::run()
{
	using clock = std::chrono::high_resolution_clock;
	constexpr app::time::nanoseconds updateStep =
		app::time::toNanos(std::chrono::duration<double, std::milli>(1 / 60.0 * 1000.0));
	clock::time_point deltaTimePoint = clock::now();
	app::time::nanoseconds elapsedTime = updateStep;
	app::time::nanoseconds deltaRenderStep = app::time::nanoseconds::zero();

	if (!this->init()) { return EXIT_FAILURE; }

	while (m_window->isOpen())
	{
		this->pollEvents();
		deltaRenderStep =
			(elapsedTime += app::time::toNanos(clock::now() - deltaTimePoint));
		deltaTimePoint = clock::now();
		while (elapsedTime > updateStep)
		{
			this->update(updateStep);
			m_keyHandler.update();
			m_mouseHandler.update();
			elapsedTime -= updateStep;
		}
		this->render(deltaRenderStep);
	}

	return EXIT_SUCCESS;
}

bool app::Game::init()
{
	return this->createComponentDependencies()
		&& this->createSystems()
		&& this->createEntities();
}

bool app::Game::createComponentDependencies()
{
	try
	{
		entt::connect<comp::Grid>(m_registry.construction<comp::RenderGrid>());
		return true;
	}
	catch (std::exception const & e)
	{
		app::Console::writeLine({ "Error: [", e.what(), "]"});
		return false;
	}
}

bool app::Game::createSystems()
{
	try
	{
		m_window = std::make_unique<app::gra::SfWindow>(m_keyHandler, m_mouseHandler,
			app::gra::SfWindowParams("Ai Lab 6", 1366u, 768u, app::gra::WindowStyle::Default));

		m_updateSystems = {
			std::make_unique<app::sys::GridClickSystem>(m_mouseHandler, m_keyHandler)
		};

		m_renderSystems = {
			std::make_unique<app::sys::RenderRectSystem>(*m_window),
			std::make_unique<app::sys::RenderGridSystem>(*m_window)
		};

		return true;
	}
	catch (std::exception const & e)
	{
		app::Console::writeLine({ "Error: [", e.what(), "]" });
		return false;
	}
}

bool app::Game::createEntities()
{
	try
	{
		js::json file = app::util::JsonLoader::load("./res/entities.json");
		if (auto const & jsonGrid = file.find("grid"); jsonGrid != file.end())
		{
			app::fact::GridFactory(*jsonGrid).create();
		}
		if (auto const & jsonBackground = file.find("background"); jsonBackground != file.end())
		{
			app::fact::EntityJsonFactory(*jsonBackground).create();
		}

		return true;
	}
	catch (std::exception const & e)
	{
		app::Console::writeLine({ "Error: [", e.what(), "]" });
		return false;
	}
}

void app::Game::pollEvents()
{
	m_window->pollEvents();
}

void app::Game::update(app::time::nanoseconds const & dt)
{
	for (std::unique_ptr<sys::BaseSystem> const & uptrSystem : m_updateSystems) { uptrSystem->update(dt); }
}

void app::Game::render(app::time::nanoseconds const & dt)
{
	m_window->clear();
	for (std::unique_ptr<sys::BaseSystem> const & uptrSystem : m_renderSystems) { uptrSystem->update(dt); }
	m_window->display();
}
