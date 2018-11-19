#ifndef _GRAPHICS_SDL_DELETER_H
#ifdef _USE_SDL
#define _GRAPHICS_SDL_DELETER_H

namespace app::gra
{
	class SDLDeleter
	{
	public: // Constructors/Destructor/Assignments
		SDLDeleter() = default;
		SDLDeleter(SDLDeleter const &) = default;
		SDLDeleter(SDLDeleter &&) = default;

		~SDLDeleter() = default;

		SDLDeleter & operator=(SDLDeleter const &) = default;
		SDLDeleter & operator=(SDLDeleter &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
	public: // Public Static Variables
	public: // Public Member Variables
		void operator()(SDL_Window * ptr) const { if (ptr != nullptr) SDL_DestroyWindow(ptr); }
		void operator()(SDL_Renderer * ptr) const { if (ptr != nullptr) SDL_DestroyRenderer(ptr); }
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

#endif // _USE_SDL
#endif // !_GRAPHICS_SDL_DELETER_H
