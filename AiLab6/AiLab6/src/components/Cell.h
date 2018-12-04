#ifndef _COMPONENT_CELL_H
#define _COMPONENT_CELL_H

#include "math/Vector2.h"

namespace app::comp
{
	struct Cell
	{
	public: // Constructors/Destructor/Assignments
		Cell() = default;
		~Cell() = default;

		Cell(Cell const &) = default;
		Cell & operator=(Cell const &) = default;

		Cell(Cell &&) = default;
		Cell & operator=(Cell &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
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
	};

	void to_json(js::json & j, app::comp::Cell const & cell);
	void from_json(js::json const & j, app::comp::Cell & cell);
}

#endif // !_COMPONENT_CELL_H
