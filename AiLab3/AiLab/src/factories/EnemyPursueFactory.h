#ifndef _ENEMY_PURSUE_FACTORY_H
#define _ENEMY_PURSUE_FACTORY_H

#include "BaseFactory.h"

#include "components/Location.h"
#include "components/Dimensions.h"
#include "components/Motion.h"
#include "components/Collision.h"
#include "components/ConeVision.h"
#include "components/Render.h"
#include "components/AiPursue.h"

namespace app::fact
{
	class EnemyPursueFactory : public BaseFactory
	{
	public: // Constructors/Destructor/Assignments
		EnemyPursueFactory(app::Registry & registry, comp::Location location, comp::Dimensions dimensions, comp::Motion motion,
			comp::Collision collision, comp::ConeVision coneVision, comp::Render render, comp::AiPursue aiPursue);

		EnemyPursueFactory() = delete;
		EnemyPursueFactory(EnemyPursueFactory const &) = default;
		EnemyPursueFactory(EnemyPursueFactory &&) = default;

		~EnemyPursueFactory() = default;

		EnemyPursueFactory & operator=(EnemyPursueFactory const &) = default;
		EnemyPursueFactory & operator=(EnemyPursueFactory &&) = default;

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
		comp::Location m_location;
		comp::Dimensions m_dimensions;
		comp::Motion m_motion;
		comp::Collision m_collision;
		comp::ConeVision m_coneVision;
		comp::Render m_render;
		comp::AiPursue m_aiPursue;
	};
}

#endif // !_ENEMY_PURSUE_FACTORY_H
