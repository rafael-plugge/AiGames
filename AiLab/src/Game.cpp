#include "stdafx.h"
#include "Game.h"

const sf::Color g::Game::_ClearColor = { 0u, 0u, 0u, 255u };

g::Game::Game()
	: _gameLoop()
	, _window()
	, _windowBuffer()
	, _windowTitle()
	, _event()
	, _player(_window)
	, _enemy(_window)
{
}

int g::Game::run()
{
	using clock = std::chrono::high_resolution_clock;
	clock::time_point deltaTimePoint = clock::now();
	clock::duration elapsedTime = clock::duration::zero();

	if (bool success = this->init(); !success) { return EXIT_FAILURE; }

	while (_gameLoop)
	{
		this->pollEvents();
		elapsedTime += std::chrono::duration_cast<clock::duration>(clock::now() - deltaTimePoint);
		deltaTimePoint = clock::now();
		while (elapsedTime > _UpdateStep)
		{
			this->update();
			elapsedTime -= _UpdateStep;
		}
		this->render();
	}

	_window.close();
	return EXIT_SUCCESS;
}

bool g::Game::init()
{
	try
	{
		_gameLoop = true;
		_windowBuffer = sf::VideoMode(1366u, 768u, 32u);
		_windowTitle = "Ai Games Lab";

		_window.create(_windowBuffer, _windowTitle, sf::Style::Default);

		return true;
	}
	catch (const std::exception& e)
	{
		std::cout << "Error in Game::init() -> " << e.what() << std::endl;
		return false;
	}
}

void g::Game::pollEvents()
{
	while (_window.pollEvent(_event))
	{
		switch (_event.type)
		{
		case sf::Event::Closed:
			_gameLoop = false;
			break;
		case sf::Event::KeyPressed:
			_keyhandler.updateKey(_event.key.code, true);
			if (_event.key.code == sf::Keyboard::Key::Up) { _player.incrementSpeedKey(true); }
			if (_event.key.code == sf::Keyboard::Key::Down) { _player.decrementSpeedKey(true); }
			break;
		case sf::Event::KeyReleased:
			_keyhandler.updateKey(_event.key.code, false);
			if (_event.key.code == sf::Keyboard::Key::Up) { _player.incrementSpeedKey(false); }
			if (_event.key.code == sf::Keyboard::Key::Down) { _player.decrementSpeedKey(false); }
			break;
		default:
			break;
		}
	}
}

void g::Game::update()
{
	if (_keyhandler.isKeyPressed(sf::Keyboard::Key::Space)) { _enemy.generateNewDirection(); }
	_player.update();
	_enemy.update();

	_keyhandler.update();
}

void g::Game::render()
{
	_window.clear(_ClearColor);

	_player.render();
	_enemy.render();

	_window.display();
}
