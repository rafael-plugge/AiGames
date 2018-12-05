#ifndef _UTILS_COLLISION_CHECKING_H
#define _UTILS_COLLISION_CHECKING_H

namespace app::util
{
	class CollisionChecking
	{
	private: // Constructors/Destructor/Assignments
		CollisionChecking() = default;
		~CollisionChecking() = default;

		CollisionChecking(CollisionChecking const &) = default;
		CollisionChecking & operator=(CollisionChecking const &) = default;

		CollisionChecking(CollisionChecking &&) = default;
		CollisionChecking & operator=(CollisionChecking &&) = default;

	public: // Public Static Functions
		static bool pointToRectangle(math::Vector2f const & point, math::Vector2f const & rectPosition, math::Vector2f const & rectSize);
	public: // Public Member Functions
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

#endif // !_UTILS_COLLISION_CHECKING_H
