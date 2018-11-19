#ifndef _GRAPHICS_WINDOW_PARAMS_H
#define _GRAPHICS_WINDOW_PARAMS_H

#include "WindowStyle.h"

namespace app::gra
{
	struct WindowParams
	{
	public: // Constructors/Destructor/Assignments
		WindowParams(std::string title = s_defaultTitle
			, std::size_t width = s_defaultWidth
			, std::size_t height = s_defaultHeight
			, WindowStyle style = s_defaultStyle);
		WindowParams(WindowParams const &) = default;
		WindowParams(WindowParams &&) = default;

		~WindowParams() = default;

		WindowParams & operator=(WindowParams const &) = default;
		WindowParams & operator=(WindowParams &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
	public: // Public Static Variables
	public: // Public Member Variables
		std::size_t width, height;
		std::string title;
		WindowStyle style;
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
		static const std::string s_defaultTitle;
		static constexpr std::size_t s_defaultWidth = 800u;
		static constexpr std::size_t s_defaultHeight = 600u;
		static constexpr WindowStyle s_defaultStyle = WindowStyle::Default;
	protected: // Protected Member Variables
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables
	};
}

#endif // !_GRAPHICS_WINDOW_PARAMS_H
