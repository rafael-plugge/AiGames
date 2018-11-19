#ifndef _AI_FORMATION_COMP_H
#define _AI_FORMATION_COMP_H

namespace app::comp
{
	struct AiFormation
	{
	public: // Constructors/Destructor/Assignments
		AiFormation() = default;
		AiFormation(AiFormation const &) = default;
		AiFormation(AiFormation &&) = default;

		~AiFormation() = default;

		AiFormation & operator=(AiFormation const &) = default;
		AiFormation & operator=(AiFormation &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
	public: // Public Static Variables
	public: // Public Member Variables
		app::Entity leader;
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

#endif // !_AI_FORMATION_COMP_H
