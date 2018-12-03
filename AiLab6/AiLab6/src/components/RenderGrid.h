#ifndef _COMPONENT_RENDER_GRID_H
#define _COMPONENT_RENDER_GRID_H

#include "math/Vector2.h"

namespace app::comp
{
	struct RenderGrid
	{
	public: // Constructors/Destructor/Assignments
		RenderGrid() = default;
		~RenderGrid() = default;

		RenderGrid(RenderGrid const &) = default;
		RenderGrid & operator=(RenderGrid const &) = default;

		RenderGrid(RenderGrid &&) = default;
		RenderGrid & operator=(RenderGrid &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
	public: // Public Static Variables
	public: // Public Member Variables
		math::Vector2f size = { 0.0f, 0.0f };
		std::optional<sf::Color> stroke;
		std::optional<float> thickness;
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables
	};

	void to_json(js::json & j, app::comp::RenderGrid const & renderGrid);
	void from_json(js::json const & j, app::comp::RenderGrid & renderGrid);
}

#endif // !_COMPONENT_RENDER_GRID_H
