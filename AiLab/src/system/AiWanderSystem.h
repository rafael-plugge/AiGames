#ifndef _AI_WANDER_SYSTEM_H
#define _AI_WANDER_SYSTEM_H

#include "BaseSystem.h"

namespace app::sys
{
	class AiWanderSystem : public BaseSystem
	{
	public: // Constructors/Destructor/Assignments
		AiWanderSystem(app::Registry & registry);

		AiWanderSystem() = delete;
		AiWanderSystem(AiWanderSystem const &) = default;
		AiWanderSystem(AiWanderSystem &&) = default;

		~AiWanderSystem() = default;

		AiWanderSystem & operator=(AiWanderSystem const &) = default;
		AiWanderSystem & operator=(AiWanderSystem &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
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

	};
}

#endif // !_AI_WANDER_SYSTEM_H
