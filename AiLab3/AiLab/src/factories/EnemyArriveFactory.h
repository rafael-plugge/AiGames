﻿#ifndef _ENEMY_ARRIVE_FACTORY_H
#define _ENEMY_ARRIVE_FACTORY_H

#include "BaseFactory.h"

#include "components/Location.h"
#include "components/Dimensions.h"
#include "components/Motion.h"
#include "components/Collision.h"
#include "components/ConeVision.h"
#include "components/Render.h"
#include "components/AiSeek.h"
#include "components/AiArrive.h"

namespace app::fact
{
	class EnemyArriveFactory : public BaseFactory
	{
	public: // Constructors/Destructor/Assignments
		EnemyArriveFactory(app::Registry & registry,
			comp::Location location, comp::Dimensions dimensions,
			comp::Motion motion, comp::Collision collision, comp::ConeVision coneVision,
			comp::Render render, comp::AiSeek aiSeek, comp::AiArrive aiArrive);

		EnemyArriveFactory() = delete;
		EnemyArriveFactory(EnemyArriveFactory const &) = default;
		EnemyArriveFactory(EnemyArriveFactory &&) = default;

		~EnemyArriveFactory() = default;

		EnemyArriveFactory & operator=(EnemyArriveFactory const &) = default;
		EnemyArriveFactory & operator=(EnemyArriveFactory &&) = default;

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
		comp::AiSeek m_aiSeek;
		comp::AiArrive m_aiArrive;
	};
}

#endif // !_ENEMY_ARRIVE_FACTORY_H
