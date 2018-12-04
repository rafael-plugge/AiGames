#ifndef _FACTORY_GRID_H
#define _FACTORY_GRID_H

#include "EntityFactory.h"

namespace app::fact
{
	class GridFactory : public EntityFactory
	{
	public: // Constructors/Destructor/Assignments
		GridFactory(js::json const & j);
		~GridFactory() = default;

		GridFactory(GridFactory const &) = default;
		GridFactory & operator=(GridFactory const &) = default;

		GridFactory(GridFactory &&) = default;
		GridFactory & operator=(GridFactory &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		virtual std::optional<app::Entity const> create() override;
	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
		js::json const & m_json;
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables
	};
}

#endif // !_FACTORY_GRID_H
