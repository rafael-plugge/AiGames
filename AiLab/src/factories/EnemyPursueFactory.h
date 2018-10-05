#ifndef _ENEMY_PURSUE_FACTORY_H
#define _ENEMY_PURSUE_FACTORY_H

#include "BaseFactory.h"

namespace app::fact
{
	class EnemyPursueFactory : public BaseFactory
	{
	public: // Constructors/Destructor/Assignments
		EnemyPursueFactory(app::Registry & registry);

		EnemyPursueFactory() = delete;
		EnemyPursueFactory(EnemyPursueFactory const &) = default;
		EnemyPursueFactory(EnemyPursueFactory &&) = default;

		~EnemyPursueFactory() = default;

		EnemyPursueFactory & operator=(EnemyPursueFactory const &) = default;
		EnemyPursueFactory & operator=(EnemyPursueFactory &&) = default;

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

#endif // !_ENEMY_PURSUE_FACTORY_H
