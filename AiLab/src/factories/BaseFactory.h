#ifndef _BASE_FACTORY_H
#define _BASE_FACTORY_H

namespace app::fact
{
	class BaseFactory
	{
	public: // Constructors/Destructor/Assignments
		BaseFactory(app::Registry & registry);

		BaseFactory() = delete;
		BaseFactory(BaseFactory const &) = default;
		BaseFactory(BaseFactory &&) = default;

		~BaseFactory() = default;

		BaseFactory & operator=(BaseFactory const &) = default;
		BaseFactory & operator=(BaseFactory &&) = default;

	public: // Public Static Functions
		virtual app::Entity create() = 0;
	public: // Public Member Functions
	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
		app::Registry & m_registry;
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables

	};
}

#endif // !_BASE_FACTORY_H
