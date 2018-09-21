#include "stdafx.h"
#include "MotionSystem.h"
#include "components/Location.h"
#include "components/Motion.h"
#include "components/MotionInput.h"

app::sys::MotionSystem::MotionSystem(app::Registry & registry)
	: BaseSystem(registry)
	, m_Acceleration(0.3f)
	, m_AngularAcceleration(0.1f)
	, m_MaxSpeed(2.0f)
	, m_MaxAngularSpeed(1.0f)
{
}

void app::sys::MotionSystem::update(app::seconds const & dt)
{
	auto view = m_registry.view<comp::Location, comp::Motion>();
	auto const dtf = static_cast<float>(dt.count());
	view.each([this](auto entity, comp::Location & location, comp::Motion & motion) -> void
	{
		if (m_registry.has<comp::MotionInput>(entity))
		{
			comp::MotionInput & motionInput = m_registry.get<comp::MotionInput>(entity);
			if (motionInput.increaseSpeed) { motion.speed += m_Acceleration; }
			if (motionInput.decreaseSpeed) { motion.speed -= m_Acceleration; }
			if (!(motionInput.rotateLeft && motionInput.rotateRight)) { motion.angularSpeed = 0.0f; }
			if (motionInput.rotateRight) { motion.angularSpeed = m_MaxAngularSpeed; }
			if (motionInput.rotateLeft) { motion.angularSpeed = -m_MaxAngularSpeed; }
		}
		if (motion.speed > m_MaxSpeed) { motion.speed = m_MaxSpeed; }
		if (motion.speed < -m_MaxSpeed) { motion.speed = -m_MaxSpeed; }
		// Only for applying angular acceleration
		//if (motion.angularSpeed > m_MaxAngularSpeed) { motion.angularSpeed = m_MaxAngularSpeed; }
		//if (motion.angularSpeed < -m_MaxAngularSpeed) { motion.angularSpeed = -m_MaxAngularSpeed; }
		location.angle += motion.angularSpeed;
		auto const angleRad = location.angle * (app::pi<float>() / 180.0f);
		location.position += sf::Vector2f{ std::sinf(angleRad), -std::cosf(angleRad) } * motion.speed;
	});
}
