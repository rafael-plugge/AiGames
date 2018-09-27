#ifndef _ENEMY_WANDER_FACTORY_H
#define _ENEMY_WANDER_FACTORY_H

#include "BaseFactory.h"

namespace app::fact
{
	class EnemyWanderFactory : public BaseFactory
	{
	public: // Constructors/Destructor/Assignments
		EnemyWanderFactory(app::Registry & registry);

		EnemyWanderFactory() = delete;
		EnemyWanderFactory(EnemyWanderFactory const &) = default;
		EnemyWanderFactory(EnemyWanderFactory &&) = default;

		~EnemyWanderFactory() = default;

		EnemyWanderFactory & operator=(EnemyWanderFactory const &) = default;
		EnemyWanderFactory & operator=(EnemyWanderFactory &&) = default;

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

#endif // !_ENEMY_WANDER_FACTORY_H
