#ifndef _GRAPHICS_SFML_WINDOW_H
#ifdef _USE_SFML
#define _GRAPHICS_SFML_WINDOW_H

#include "Window.h"
#include "SfWindowParams.h"
#include "input/Keyhandler.h"
#include "input/MouseHandler.h"

namespace app::gra
{
	class SfWindow : public Window
	{
	public: // Constructors/Destructor/Assignments
		SfWindow(app::inp::Keyhandler & keyHandler, app::inp::Mousehandler & mouseHandler);
		SfWindow(app::inp::Keyhandler & keyHandler, app::inp::Mousehandler & mouseHandler, SfWindowParams const parameters);

		virtual ~SfWindow();

		SfWindow & operator=(SfWindow const &) = delete;
		SfWindow(SfWindow const &) = delete;

		SfWindow & operator=(SfWindow &&) = default;
		SfWindow(SfWindow &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		bool create(SfWindowParams const parameters);
		// Inherited via Window
		virtual void pollEvents() override;
		virtual void clear() const override;
		void draw(sf::Drawable const & drawable, sf::RenderStates const & states = sf::RenderStates::Default);
		virtual void display() const override;
	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
	private: // Private Static Functions
		static const sf::Color backgroundColor() { return sf::Color(s_backgroundColor.r, s_backgroundColor.g, s_backgroundColor.b, s_backgroundColor.a); }
	private: // Private Member Functions
		std::uint32_t createStyle(WindowStyle const & style) const;
	private: // Private Static Variables
		static const sf::Color s_clearColor;
	private: // Private Member Variables
		sf::ContextSettings m_contextSettings;
		std::unique_ptr<sf::RenderWindow> m_sfWindow;
		app::inp::Keyhandler & m_keyHandler;
		app::inp::Mousehandler & m_mouseHandler;
	};
}

#endif // _USE_SFML
#endif // !_GRAPHICS_SFML_WINDOW_H
