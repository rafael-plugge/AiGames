#ifndef _CELL_CLICK_SYSTEM_H
#define _CELL_CLICK_SYSTEM_H

#include "BaseSystem.h"

#include "input/MouseHandler.h"

#include "components/Location.h"
#include "components/Dimensions.h"
#include "components/Cell.h"

namespace app::sys
{
	class CellClickSystem : public BaseSystem
	{
	private: // Private typedefs/usings/enums
		using VectorCallback = 
			std::vector<std::function<void(app::Entity const, comp::Location &, comp::Dimensions &, comp::Cell &)>>;
	public: // Constructors/Destructor/Assignments
		CellClickSystem(app::inp::Mousehandler const & mouseHandler);
		CellClickSystem(app::inp::Mousehandler const & mouseHandler, VectorCallback::value_type const & callback);
		CellClickSystem(app::inp::Mousehandler const & mouseHandler, VectorCallback const & callbacks);
		~CellClickSystem() = default;

		CellClickSystem(CellClickSystem const &) = default;
		CellClickSystem & operator=(CellClickSystem const &) = default;

		CellClickSystem(CellClickSystem &&) = default;
		CellClickSystem & operator=(CellClickSystem &&) = default;

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
		constexpr bool rectCollision(math::Vector2i const & pos, comp::Location const & location, comp::Dimensions const & dimensions);
	private: // Private Static Variables
	private: // Private Member Variables
		app::inp::Mousehandler const & m_mouseHandler;
		VectorCallback const m_callbacks;
	};
}

#endif // !_CELL_CLICK_SYSTEM_H
