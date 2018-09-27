#pragma once

#include "utilities/Keyhandler.h"
#include "system/BaseSystem.h"

namespace app
{
	class Game
	{
	public:
		Game();
		~Game() = default;
		int run();
	private:
		bool init();
		bool createCompDependencies();
		bool createSystems();
		bool createEntities();

		void pollEvents();
		void update(app::seconds const & dt);
		void render();

	private: // member variables
		bool m_gameLoop;
		
		// rendering
		sf::RenderWindow m_window;
		sf::VideoMode m_windowBuffer;
		sf::Vector2f m_windowSize;
		std::string m_windowTitle;

		// Events
		sf::Event m_event;
		utils::Keyhandler<sf::Keyboard::Key> m_keyHandler;

		// Entity Component System
		entt::DefaultRegistry m_registry;
		std::array<std::unique_ptr<sys::BaseSystem>, 5> m_updateSystems;
		std::array<std::unique_ptr<sys::BaseSystem>, 1> m_renderSystems;

	private: // static variables
		static const sf::Color s_clearColor;
		static constexpr std::chrono::nanoseconds s_updateStep = 
			std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::duration<float, std::milli>(1 / 60.0f * 1000.0f));
		static constexpr app::seconds s_updateStepSec =
			std::chrono::duration_cast<app::seconds>(std::chrono::duration<double, std::milli>(1 / 60.0 * 1000.0));
	};
}
