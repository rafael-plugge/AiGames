#pragma once

#include "BaseSystem.h"

namespace app::sys
{
	class MotionSystem : public BaseSystem
	{
	public:
		MotionSystem(app::Registry & registry);

		virtual void update(app::seconds const & dt) override;
	};

}