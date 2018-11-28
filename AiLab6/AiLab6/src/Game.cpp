#include "stdafx.h"
#include "Game.h"

#include "graphics/SfWindow.h"

app::Game::Game()
	: m_window(nullptr)
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
			elapsedTime -= updateStep;
		}
		this->render(deltaRenderStep);
	}

	return EXIT_SUCCESS;
}

bool app::Game::init()
{
	auto uptrWindow = std::make_unique<app::gra::SfWindow>(
		app::gra::SfWindowParams("Ai Lab 6", 1366u, 768u));
	m_window = std::move(uptrWindow);

	return true;
}

void app::Game::pollEvents()
{
	m_window->pollEvents();
}

void app::Game::update(app::time::nanoseconds const & dt)
{
}

void app::Game::render(app::time::nanoseconds const & dt)
{
	m_window->clear();
	m_window->display();
}
