#ifndef _COMPONENTS_DIMENSION_H
#define _COMPONENTS_DIMENSION_H

#include "math/Vector2.h"

namespace app::comp
{
	struct Dimensions
	{
	public: // Constructors/Destructor/Assignments
		Dimensions() = default;
		Dimensions(Dimensions const &) = default;
		Dimensions(Dimensions &&) = default;

		~Dimensions() = default;

		Dimensions & operator=(Dimensions const &) = default;
		Dimensions & operator=(Dimensions &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
	public: // Public Static Variables
	public: // Public Member Variables
		math::Vector2f size = { 0.0f, 0.0f };
		math::Vector2f origin = { 0.0f, 0.0f };
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables
	};

	void to_json(js::json & j, app::comp::Dimensions const & dimensions);
	void from_json(js::json const & j, app::comp::Dimensions & dimensions);
}

#endif // !_COMPONENTS_DIMENSION_H
