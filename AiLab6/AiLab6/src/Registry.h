#ifndef _REGISTRY_H
#define _REGISTRY_H

namespace app
{
	using Entity = std::uint32_t;
	using Registry = ::entt::Registry<Entity>;

	class Reg
	{
	private: // Constructors/Destructor/Assignments
		Reg() = default;
		~Reg() = default;

		Reg(Reg const &) = default;
		Reg & operator=(Reg const &) = default;

		Reg(Reg &&) = default;
		Reg & operator=(Reg &&) = default;

	public: // Public Static Functions
		static Registry & get();
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
		static std::unique_ptr<Registry> s_registry;
	private: // Private Member Variables
	};
}

#endif // !_REGISTRY_H
