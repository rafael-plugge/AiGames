#ifndef _COMPONENTS_LOCATION_H
#define _COMPONENTS_LOCATION_H

#include "math/Vector2.h"

namespace app::comp
{
	struct Location
	{
	public: // Constructors/Destructor/Assignments
		Location() = default;
		Location(Location const &) = default;
		Location(Location &&) = default;

		~Location() = default;

		Location & operator=(Location const &) = default;
		Location & operator=(Location &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
	public: // Public Static Variables
	public: // Public Member Variables
		math::Vector2f position = { 0.0f, 0.0f };
		float orientation = 0.0f;
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables
	};

	void to_json(js::json & j, app::comp::Location const & location);
	void from_json(js::json const & j, app::comp::Location & location);
}

#endif // !_COMPONENTS_LOCATION_H
