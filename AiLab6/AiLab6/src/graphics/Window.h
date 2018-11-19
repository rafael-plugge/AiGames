#ifndef _GRAPHICS_WINDOW_H
#define _GRAPHICS_WINDOW_H

#include "WindowParams.h"

namespace app::gra
{
	class Window
	{
	public: // Constructors/Destructor/Assignments
		Window();
		Window(WindowParams const parameters);

		virtual ~Window();

		Window(Window const &) = delete;
		Window & operator=(Window const &) = delete;

		Window(Window &&) = default;
		Window & operator=(Window &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		constexpr bool const & isOpen() { return m_open; }
		virtual void pollEvents() abstract;
		virtual void clear() const abstract;
		virtual void display() const abstract;
	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
		struct Color
		{
			std::uint8_t r, g, b, a;
		};
		static constexpr Color s_backgroundColor = { 0u, 0u, 0u, 255u };
	protected: // Protected Member Variables
		bool m_open;
		struct
		{
			std::size_t width, height;
		}m_size;
		std::string m_title;
		WindowStyle m_style;
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables
	};
}

#endif // !_GRAPHICS_WINDOW_H
