#pragma once

#include "BaseSystem.h"

namespace app::sys
{
	class MotionSystem : public BaseSystem
	{
	public:
		MotionSystem(app::Registry & registry);

		virtual void update(app::seconds const & dt) override;
	private:
		const float m_Acceleration;
		const float m_AngularAcceleration;

		const float m_MaxSpeed;
		const float m_MaxAngularSpeed;
	};

}