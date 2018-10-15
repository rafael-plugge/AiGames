#ifndef _CONE_VISION_COMP_H
#define _CONE_VISION_COMP_H

namespace app::comp
{
	struct ConeVision
	{
	public: // Constructors/Destructor/Assignments
		ConeVision() = default;
		ConeVision(ConeVision const &) = default;
		ConeVision(ConeVision &&) = default;

		~ConeVision() = default;

		ConeVision & operator=(ConeVision const &) = default;
		ConeVision & operator=(ConeVision &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
	public: // Public Static Variables
	public: // Public Member Variables
		float radius;
		float angle;
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

#endif // !_CONE_VISION_COMP_H
