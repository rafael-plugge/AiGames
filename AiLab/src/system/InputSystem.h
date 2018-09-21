#pragma once

#include "BaseSystem.h"
#include "utilities/Keyhandler.h"

namespace app::sys
{
	class InputSystem : public BaseSystem
	{
	private:
		typedef sf::Keyboard::Key Key;
	public:
		InputSystem(app::Registry & registry, utils::Keyhandler<Key> & keyHandler);

		virtual void update(app::seconds const & dt) override;
	private:
		utils::Keyhandler<Key> & m_keyHandler;
	};

}