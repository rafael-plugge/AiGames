#ifndef _ENEMY_FLEE_FACTORY_H
#define _ENEMY_FLEE_FACTORY_H

#include "BaseFactory.h"

namespace app::fact
{
	class EnemyFleeFactory : public BaseFactory
	{
	public: // Constructors/Destructor/Assignments
		EnemyFleeFactory(app::Registry & registry);

		EnemyFleeFactory() = delete;
		EnemyFleeFactory(EnemyFleeFactory const &) = default;
		EnemyFleeFactory(EnemyFleeFactory &&) = default;

		~EnemyFleeFactory() = default;

		EnemyFleeFactory & operator=(EnemyFleeFactory const &) = default;
		EnemyFleeFactory & operator=(EnemyFleeFactory &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		virtual app::Entity create() override;
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

#endif // !_ENEMY_FLEE_FACTORY_H
