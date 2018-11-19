#ifndef _AI_FORMATION_SYSTEM_H
#define _AI_FORMATION_SYSTEM_H

#include "BaseSystem.h"

namespace app::sys
{
	class AiFormationSystem : public BaseSystem
	{
	public: // Constructors/Destructor/Assignments
		AiFormationSystem(app::Registry & registry);

		AiFormationSystem() = delete;
		AiFormationSystem(AiFormationSystem const &) = default;
		AiFormationSystem(AiFormationSystem &&) = default;

		~AiFormationSystem() = default;

		AiFormationSystem & operator=(AiFormationSystem const &) = default;
		AiFormationSystem & operator=(AiFormationSystem &&) = default;

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

#endif // !_AI_FORMATION_SYSTEM_H
