#ifndef _AI_PURSUE_SYSTEM_H
#define _AI_PURSUE_SYSTEM_H

#include "BaseSystem.h"

namespace app::sys
{
	class AiPursueSystem : public BaseSystem
	{
	public: // Constructors/Destructor/Assignments
		AiPursueSystem(app::Registry & registry);

		AiPursueSystem() = delete;
		AiPursueSystem(AiPursueSystem const &) = default;
		AiPursueSystem(AiPursueSystem &&) = default;

		~AiPursueSystem();

		AiPursueSystem & operator=(AiPursueSystem const &) = default;
		AiPursueSystem & operator=(AiPursueSystem &&) = default;

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

#endif // !_AI_PURSUE_SYSTEM_H
