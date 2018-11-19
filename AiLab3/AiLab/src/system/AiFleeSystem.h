#ifndef _AI_FLEE_SYSTEM_H
#define _AI_FLEE_SYSTEM_H

#include "BaseSystem.h"

namespace app::sys
{
	class AiFleeSystem : public BaseSystem
	{
	public: // Constructors/Destructor/Assignments
		AiFleeSystem(app::Registry & registry);

		AiFleeSystem() = delete;
		AiFleeSystem(AiFleeSystem const &) = default;
		AiFleeSystem(AiFleeSystem &&) = default;

		~AiFleeSystem();

		AiFleeSystem & operator=(AiFleeSystem const &) = default;
		AiFleeSystem & operator=(AiFleeSystem &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		void player(app::Registry & registry, app::Entity entity);
		virtual void update(app::seconds const & dt) override;
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
		std::optional<app::Entity> m_player;
	};
}

#endif // !_AI_FLEE_SYSTEM_H
