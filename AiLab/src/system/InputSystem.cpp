#include "stdafx.h"
#include "InputSystem.h"
#include "components/MotionInput.h"

app::sys::InputSystem::InputSystem(app::Registry & registry, utils::Keyhandler<InputSystem::Key> & keyHandler)
	: BaseSystem(registry)
	, m_keyHandler(keyHandler)
{
}

void app::sys::InputSystem::update(app::seconds const & dt)
{
	auto view = m_registry.view<comp::MotionInput>();
	view.each([this](app::Entity const & entity, comp::MotionInput & motionInput) -> void
	{
		motionInput.increaseSpeed = m_keyHandler.isKeyDown({ Key::Up, Key::W });
		motionInput.decreaseSpeed = m_keyHandler.isKeyDown({ Key::Down, Key::S });
		motionInput.rotateLeft = m_keyHandler.isKeyDown({ Key::Left, Key::A });
		motionInput.rotateRight = m_keyHandler.isKeyDown({ Key::Right, Key::D });
		motionInput.stop = m_keyHandler.isKeyDown(Key::Space);
	});
}
