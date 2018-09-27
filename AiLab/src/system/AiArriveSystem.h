#ifndef _AI_ARRIVE_SYSTEM_H
#define _AI_ARRIVE_SYSTEM_H

#include "BaseSystem.h"

namespace app::sys
{
	class AiArriveSystem : public BaseSystem
	{
	public: // Constructors/Destructor/Assignments
		AiArriveSystem(app::Registry & registry);

		AiArriveSystem() = delete;
		AiArriveSystem(AiArriveSystem const &) = default;
		AiArriveSystem(AiArriveSystem &&) = default;

		~AiArriveSystem();

		AiArriveSystem & operator=(AiArriveSystem const &) = default;
		AiArriveSystem & operator=(AiArriveSystem &&) = default;

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
		float const m_minimumSpeed;
	};
}

#endif // !_AI_ARRIVE_SYSTEM_H
