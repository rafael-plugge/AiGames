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
	view.each([this](auto entity, comp::MotionInput & motionInput) -> void
	{
		motionInput.increaseSpeed = m_keyHandler.isKeyDown(Key::Up);
		motionInput.decreaseSpeed = m_keyHandler.isKeyDown(Key::Down);
		motionInput.rotateLeft = m_keyHandler.isKeyDown(Key::Left);
		motionInput.rotateRight = m_keyHandler.isKeyDown(Key::Right);
	});
}
