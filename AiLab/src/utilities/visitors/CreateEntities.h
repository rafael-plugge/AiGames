#ifndef _CREATE_ENTITIES_H
#define _CREATE_ENTITIES_H

#include "factories/EnemyFactory.h"
#include "factories/PlayerFactory.h"

namespace app::visitor
{
	class CreateEntities
	{
	public: // Constructors/Destructor/Assignments
		CreateEntities() = default;
		CreateEntities(CreateEntities const &) = default;
		CreateEntities(CreateEntities &&) = default;

		~CreateEntities() = default;

		CreateEntities & operator=(CreateEntities const &) = default;
		CreateEntities & operator=(CreateEntities &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		void operator()(app::fact::EnemyFactory & enemyFactory);
		void operator()(app::fact::PlayerFactory & playerFactory);
		void operator()(app::fact::BaseFactory & baseFactory);
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
}

#endif // !_CREATE_ENTITIES_H
