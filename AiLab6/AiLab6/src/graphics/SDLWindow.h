#ifndef _GRAPHICS_SDL_WINDOW_H
#ifdef _USE_SDL
#define _GRAPHICS_SDL_WINDOW_H

#include "Window.h"
#include "SDLWindowParams.h"
#include "SDLDeleter.h"

namespace app::gra
{
	class SDLWindow : public Window
	{
	public: // Constructors/Destructor/Assignments
		SDLWindow();
		SDLWindow(SDLWindowParams const parameters);

		virtual ~SDLWindow();

		SDLWindow(SDLWindow const &) = delete;
		SDLWindow & operator=(SDLWindow const &) = default;

		SDLWindow(SDLWindow &&) = delete;
		SDLWindow & operator=(SDLWindow &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		bool create(SDLWindowParams const parameters);
		// Inherited via Window
		virtual void pollEvents() override;
		virtual void clear() const override;
		virtual void display() const override;
	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
	private: // Private Static Functions
	private: // Private Member Functions
		std::unique_ptr<SDL_Window, SDLDeleter> createWindow() const;
		std::unique_ptr<SDL_Renderer, SDLDeleter> createRenderer() const;
		std::uint32_t const createStyle(WindowStyle const & style) const;
	private: // Private Static Variables
	private: // Private Member Variables
		std::shared_ptr<SDL_Window> m_sdlWindow;
		std::shared_ptr<SDL_Renderer> m_renderer;
	};
}

#endif // _USE_SDL
#endif // !_GRAPHICS_SDL_WINDOW_H
