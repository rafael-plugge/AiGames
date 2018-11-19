#ifndef _ENEMY_SEEK_FACTORY_H
#define _ENEMY_SEEK_FACTORY_H

#include "BaseFactory.h"

namespace app::fact
{
	class EnemySeekFactory : public BaseFactory
	{
	public: // Constructors/Destructor/Assignments
		EnemySeekFactory(app::Registry & registry);

		EnemySeekFactory() = delete;
		EnemySeekFactory(EnemySeekFactory const &) = default;
		EnemySeekFactory(EnemySeekFactory &&) = default;

		~EnemySeekFactory() = default;

		EnemySeekFactory & operator=(EnemySeekFactory const &) = default;
		EnemySeekFactory & operator=(EnemySeekFactory &&) = default;

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

#endif // !_ENEMY_SEEK_FACTORY_H
