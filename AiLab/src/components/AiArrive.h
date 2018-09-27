#ifndef _AI_ARRIVE_H
#define _AI_ARRIVE_H

namespace app::comp
{
	struct AiArrive
	{
	public: // Constructors/Destructor/Assignments
		AiArrive() = default;
		AiArrive(AiArrive const &) = default;
		AiArrive(AiArrive &&) = default;

		~AiArrive() = default;

		AiArrive & operator=(AiArrive const &) = default;
		AiArrive & operator=(AiArrive &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		float radius, brakeSpeed, chaseSpeed;
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

#endif // !_AI_ARRIVE_H
