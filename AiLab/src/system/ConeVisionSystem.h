#ifndef _CONE_VISION_SYSTEM_H
#define _CONE_VISION_SYSTEM_H

#include "BaseSystem.h"

namespace app::sys
{
	class ConeVisionSystem : public BaseSystem
	{
	public: // Constructors/Destructor/Assignments
		ConeVisionSystem(app::Registry & registry);

		ConeVisionSystem() = delete;
		ConeVisionSystem(ConeVisionSystem const &) = default;
		ConeVisionSystem(ConeVisionSystem &&) = default;

		~ConeVisionSystem();

		ConeVisionSystem & operator=(ConeVisionSystem const &) = default;
		ConeVisionSystem & operator=(ConeVisionSystem &&) = default;

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

#endif // !_CONE_VISION_SYSTEM_H
