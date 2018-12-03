#ifndef _FACTORIES_BACKGROUND_H
#define _FACTORIES_BACKGROUND_H

#include "EntityFactory.h"

namespace app::fact
{
	class BackgroundFactory : public EntityFactory
	{
	public: // Constructors/Destructor/Assignments
		BackgroundFactory(js::json const & j);
		virtual ~BackgroundFactory() = default;

		BackgroundFactory(BackgroundFactory const &) = default;
		BackgroundFactory & operator=(BackgroundFactory const &) = default;

		BackgroundFactory(BackgroundFactory &&) = default;
		BackgroundFactory & operator=(BackgroundFactory &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
		js::json const & m_json;
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables
	};
}

#endif // !_FACTORIES_BACKGROUND_H
