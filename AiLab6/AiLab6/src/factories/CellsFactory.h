#ifndef _FACTORY_CELL_H
#define _FACTORY_CELL_H

#include "EntityFactory.h"

namespace app::fact
{
	class CellsFactory : public EntityFactory
	{
	public: // Constructors/Destructor/Assignments
		CellsFactory(js::json const & j);
		~CellsFactory() = default;

		CellsFactory(CellsFactory const &) = default;
		CellsFactory & operator=(CellsFactory const &) = default;

		CellsFactory(CellsFactory &&) = default;
		CellsFactory & operator=(CellsFactory &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		virtual std::optional<app::Entity const> create() override;
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
		js::json const & m_json;
	};
}

#endif // !_FACTORY_CELL_H
