﻿#ifndef _GAME_H
#define _GAME_H

#include "Registry.h"

#include "graphics/SfWindow.h"

#include "systems/BaseSystem.h"

#include "utilities/Time.h"
#include "utilities/JsonLoader.h"

namespace app
{
	class Game
	{
	public: // Constructors/Destructor/Assignments
		Game();
		Game(Game const &) = default;
		Game(Game &&) = default;

		~Game();

		Game & operator=(Game const &) = default;
		Game & operator=(Game &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		int run();
	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
	private: // Private Static Functions
	private: // Private Member Functions
		bool init();
		bool createComponentDependencies();
		bool createSystems();
		bool createEntities();

		void pollEvents();
		void update(app::time::nanoseconds const & dt);
		void render(app::time::nanoseconds const & dt);
	private: // Private Static Variables
	private: // Private Member Variables
		app::Registry & m_registry;
		app::inp::Keyhandler m_keyHandler;
		app::inp::Mousehandler m_mouseHandler;
		app::gra::SfWindow m_window;
		std::array<std::unique_ptr<sys::BaseSystem>, 1> m_updateSystems;
		std::array<std::unique_ptr<sys::BaseSystem>, 2> m_renderSystems;
	};
}

#endif // !_GAME_H
