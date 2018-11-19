#ifndef _GRAPHICS_SFML_WINDOW_PARAMS_H
#define _GRAPHICS_SFML_WINDOW_PARAMS_H

#include "WindowParams.h"

namespace app::gra
{
	struct SfWindowParams : public WindowParams
	{
	public: // Constructors/Destructor/Assignments
		SfWindowParams(std::string title = s_defaultTitle
			, std::size_t width = s_defaultWidth
			, std::size_t height = s_defaultHeight
			, WindowStyle style = s_defaultStyle
			, sf::ContextSettings contextSettings = s_defaultSettings);

		SfWindowParams(SfWindowParams const &) = default;
		SfWindowParams(SfWindowParams &&) = default;

		~SfWindowParams() = default;

		SfWindowParams & operator=(SfWindowParams const &) = default;
		SfWindowParams & operator=(SfWindowParams &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
	public: // Public Static Variables
	public: // Public Member Variables
		sf::ContextSettings contextSettings;
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
		static const sf::ContextSettings s_defaultSettings;
	protected: // Protected Member Variables
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables
	};
}

#endif // !_GRAPHICS_SFML_WINDOW_PARAMS_H
