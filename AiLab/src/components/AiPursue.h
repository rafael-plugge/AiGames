#ifndef _AI_PURSUE_H
#define _AI_PURSUE_H

namespace app::comp
{
	struct AiPursue
	{
	public: // Constructors/Destructor/Assignments
		AiPursue() = default;
		AiPursue(AiPursue const &) = default;
		AiPursue(AiPursue &&) = default;

		~AiPursue() = default;

		AiPursue & operator=(AiPursue const &) = default;
		AiPursue & operator=(AiPursue &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
	public: // Public Static Variables
	public: // Public Member Variables
		int predictTimeSteps;
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

#endif // !_AI_PURSUE_H
