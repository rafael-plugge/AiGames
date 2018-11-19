#ifndef _GRAPHICS_SDL_WINDOW_PARAMS_H
#define _GRAPHICS_SDL_WINDOW_PARAMS_H

#include "WindowParams.h"

namespace app::gra
{
	struct SDLWindowParams : public WindowParams
	{
	public: // Constructors/Destructor/Assignments
		SDLWindowParams() = default;
		SDLWindowParams(SDLWindowParams const &) = default;
		SDLWindowParams(SDLWindowParams &&) = default;

		~SDLWindowParams() = default;

		SDLWindowParams & operator=(SDLWindowParams const &) = default;
		SDLWindowParams & operator=(SDLWindowParams &&) = default;

	public: // Public Static Functions
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

#endif // !_GRAPHICS_SDL_WINDOW_PARAMS_H
