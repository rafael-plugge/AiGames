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

		~AiWanderSystem();

		AiWanderSystem & operator=(AiWanderSystem const &) = default;
		AiWanderSystem & operator=(AiWanderSystem &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		void player(app::Registry & registry, app::Entity player);
		virtual void update(app::seconds const & dt) override;
	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
	private: // Private Static Functions
	private: // Private Member Functions
		float generateRandomPercentage();
	private: // Private Static Variables
	private: // Private Member Variables
		float const m_maxOffset;
		float const m_minOffset;
		float const m_stepOffset;
		std::default_random_engine m_randomEngine;
		std::uniform_real_distribution<float> m_distribution;
		float m_offset;
		bool m_increase;
		std::optional<app::Entity> m_player;
	};
}

#endif // !_AI_WANDER_SYSTEM_H
