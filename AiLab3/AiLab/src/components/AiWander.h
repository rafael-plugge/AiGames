#ifndef _AI_WANDER_H
#define _AI_WANDER_H

namespace app::comp
{
	struct AiWander
	{
	public: // Constructors/Destructor/Assignments
		AiWander() = default;
		AiWander(AiWander const &) = default;
		AiWander(AiWander &&) = default;

		~AiWander() = default;

		AiWander & operator=(AiWander const &) = default;
		AiWander & operator=(AiWander &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
	public: // Public Static Variables
	public: // Public Member Variables
		float maxMeander;
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

#endif // !_AI_WANDER_H
