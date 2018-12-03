#ifndef _FACTORY_ENTITY_JSON_H
#define _FACTORY_ENTITY_JSON_H

#include "EntityFactory.h"

namespace app::fact
{
	class EntityJsonFactory : public EntityFactory
	{
	public: // Constructors/Destructor/Assignments
		EntityJsonFactory(js::json const & j);
		virtual ~EntityJsonFactory() = default;

		EntityJsonFactory(EntityJsonFactory const &) = default;
		EntityJsonFactory & operator=(EntityJsonFactory const &) = default;

		EntityJsonFactory(EntityJsonFactory &&) = default;
		EntityJsonFactory & operator=(EntityJsonFactory &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
	public: // Public Static Variables
	public: // Public Member Variables
		virtual app::Entity const create() override;
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

#endif // !_FACTORY_ENTITY_JSON_H
