#ifndef _PLAYER_FACTORY_H
#define _PLAYER_FACTORY_H

#include "BaseFactory.h"

namespace app::fact
{
	class PlayerFactory : public BaseFactory
	{
	public: // Constructors/Destructor/Assignments
		PlayerFactory(app::Registry & registry);

		PlayerFactory() = delete;
		PlayerFactory(PlayerFactory const &) = default;
		PlayerFactory(PlayerFactory &&) = default;

		~PlayerFactory() = default;

		PlayerFactory & operator=(PlayerFactory const &) = default;
		PlayerFactory & operator=(PlayerFactory &&) = default;

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

#endif // !_PLAYER_FACTORY_H
