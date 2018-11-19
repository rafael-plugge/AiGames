#ifndef _ENEMY_FORMATION_FACTORY_H
#define _ENEMY_FORMATION_FACTORY_H

#include "BaseFactory.h"

namespace app::fact
{
	class EnemyFormationFactory : public BaseFactory
	{
	public: // Constructors/Destructor/Assignments
		EnemyFormationFactory(app::Registry & registry);

		EnemyFormationFactory() = delete;
		EnemyFormationFactory(EnemyFormationFactory const &) = default;
		EnemyFormationFactory(EnemyFormationFactory &&) = default;

		~EnemyFormationFactory() = default;

		EnemyFormationFactory & operator=(EnemyFormationFactory const &) = default;
		EnemyFormationFactory & operator=(EnemyFormationFactory &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		virtual app::Entity create() override;
	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
		virtual app::Entity createLeader();
	protected: // Protected Static Variables
	protected: // Protected Member Variables
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables

	};
}

#endif // !_ENEMY_FORMATION_FACTORY_H
