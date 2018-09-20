#include "stdafx.h"
#include "MotionSystem.h"
#include "components/Location.h"
#include "components/Motion.h"

app::sys::MotionSystem::MotionSystem(app::Registry & registry)
	: BaseSystem(registry)
{
}

void app::sys::MotionSystem::update(app::seconds const & dt)
{
	auto view = m_registry.view<comp::Location, comp::Motion>();
	auto const dtf = static_cast<float>(dt.count());
	view.each([this](auto entity, comp::Location & location, comp::Motion & motion) -> void
	{
		location.position += motion.velocity;
		location.angle += motion.angularSpeed;
	});
}
