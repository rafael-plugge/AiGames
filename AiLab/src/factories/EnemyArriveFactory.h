#ifndef _ENEMY_ARRIVE_FACTORY_H
#define _ENEMY_ARRIVE_FACTORY_H

#include "BaseFactory.h"

namespace app::fact
{
	class EnemyArriveFactory : public BaseFactory
	{
	public: // Constructors/Destructor/Assignments
		EnemyArriveFactory(app::Registry & registry);

		EnemyArriveFactory() = delete;
		EnemyArriveFactory(EnemyArriveFactory const &) = default;
		EnemyArriveFactory(EnemyArriveFactory &&) = default;

		~EnemyArriveFactory() = default;

		EnemyArriveFactory & operator=(EnemyArriveFactory const &) = default;
		EnemyArriveFactory & operator=(EnemyArriveFactory &&) = default;

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

#endif // !_ENEMY_ARRIVE_FACTORY_H
