#pragma once

#include "system/Keyhandler.h"
#include "entities/Player.h"
#include "entities/Enemy.h"

namespace g
{
	class Game
	{
	public:
		Game();
		~Game() = default;
		int run();
	private:
		bool init();
		void pollEvents();
		void update();
		void render();

	private: // member variables
		bool _gameLoop;
		
		// rendering
		sf::RenderWindow _window;
		sf::VideoMode _windowBuffer;
		std::string _windowTitle;

		// Events
		sf::Event _event;
		g::Keyhandler _keyhandler;

		// entities
		g::Player _player;
		g::Enemy _enemy;

	private: // static variables
		static const sf::Color _ClearColor;
		static constexpr std::chrono::nanoseconds _UpdateStep = 
			std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::duration<float, std::milli>(1 / 60.0f * 1000.0f));
	};
}
