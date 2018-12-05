#ifndef _COMPONENT_GRID_H
#define _COMPONENT_GRID_H

#include "lab/Block.h"

namespace app::comp
{
	struct Grid
	{
	public: // Constructors/Destructor/Assignments
		Grid() = default;
		~Grid() = default;

		Grid(Grid const &) = default;
		Grid & operator=(Grid const &) = default;

		Grid(Grid &&) = default;
		Grid & operator=(Grid &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
	public: // Public Static Variables
	public: // Public Member Variables
		std::size_t width = 0u, height = 0u;
		std::vector<std::vector<lab::Block>> blocks;
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables
	};

	void to_json(js::json & j, app::comp::Grid const & grid);
	void from_json(js::json const & j, app::comp::Grid & grid);
}

#endif // !_COMPONENT_GRID_H
