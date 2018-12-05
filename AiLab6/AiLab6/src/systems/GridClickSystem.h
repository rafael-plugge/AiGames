#ifndef _SYSTEM_GRID_CLICK_H
#define _SYSTEM_GRID_CLICK_H

#include "BaseSystem.h"

namespace app::sys
{
	class GridClickSystem : public BaseSystem
	{
	public: // Constructors/Destructor/Assignments
		GridClickSystem(app::inp::Mousehandler & mouseHandler);
		virtual ~GridClickSystem() = default;

		GridClickSystem(GridClickSystem const &) = default;
		GridClickSystem & operator=(GridClickSystem const &) = default;

		GridClickSystem(GridClickSystem &&) = default;
		GridClickSystem & operator=(GridClickSystem &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		virtual void update(app::time::nanoseconds const & dt) override;
	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables
		app::inp::Mousehandler m_mouseHandler;
	};
}

#endif // !_SYSTEM_GRID_CLICK_H
