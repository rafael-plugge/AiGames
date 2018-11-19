#pragma once

namespace app::sys
{
	class BaseSystem
	{
	public:
		BaseSystem(app::Registry & registry);

		virtual void update(app::seconds const & dt) = 0;
	protected:
		app::Registry & m_registry;

	};

}
