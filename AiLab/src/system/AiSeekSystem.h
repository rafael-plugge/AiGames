#ifndef _AI_SEEK_SYSTEM_H
#define _AI_SEEK_SYSTEM_H

#include "BaseSystem.h"

namespace app::sys
{
	class AiSeekSystem : public BaseSystem
	{
	public: // Constructors/Destructor/Assignments
		AiSeekSystem(app::Registry & registry);

		AiSeekSystem() = delete;
		AiSeekSystem(AiSeekSystem const &) = default;
		AiSeekSystem(AiSeekSystem &&) = default;

		~AiSeekSystem() = default;

		AiSeekSystem & operator=(AiSeekSystem const &) = default;
		AiSeekSystem & operator=(AiSeekSystem &&) = default;

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
		app::Entity m_player;
		const float m_maxSpeed;
	};
}

#endif // !_AI_SEEK_SYSTEM_H
