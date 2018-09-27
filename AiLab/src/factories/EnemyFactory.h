#ifndef _ENEMY_FACTORY_H
#define _ENEMY_FACTORY_H

#include "BaseFactory.h"

namespace app::fact
{
	class EnemyFactory : public BaseFactory
	{
	public: // Constructors/Destructor/Assignments
		EnemyFactory(app::Registry & registry);
		EnemyFactory(app::Registry & registry, std::string const & filePath);

		EnemyFactory() = delete;
		EnemyFactory(EnemyFactory const &) = default;
		EnemyFactory(EnemyFactory &&) = default;

		~EnemyFactory() = default;

		EnemyFactory & operator=(EnemyFactory const &) = default;
		EnemyFactory & operator=(EnemyFactory &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
	public: // Public Static Variables
	public: // Public Member Variables
		virtual app::Entity create() override;
		app::Entity create(std::string const & filePath);
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables
		std::string const m_filePath;
	};
}

#endif // !_ENEMY_FACTORY_H
