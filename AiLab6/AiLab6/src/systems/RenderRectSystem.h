#ifndef _SYSTEM_RENDER_RECT_H
#define _SYSTEM_RENDER_RECT_H

#include "BaseSystem.h"
#include "graphics/SfWindow.h"

namespace app::sys
{
	class RenderRectSystem : public sys::BaseSystem
	{
	public: // Constructors/Destructor/Assignments
		RenderRectSystem(gra::SfWindow & window);
		~RenderRectSystem() = default;

		RenderRectSystem(RenderRectSystem const &) = default;
		RenderRectSystem & operator=(RenderRectSystem const &) = default;

		RenderRectSystem(RenderRectSystem &&) = default;
		RenderRectSystem & operator=(RenderRectSystem &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		virtual void update(app::time::nanoseconds const & dt) override;
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
		gra::SfWindow & m_window;
		sf::RectangleShape m_renderShape;
		sf::RenderStates const m_renderState;
	};
}

#endif // !_SYSTEM_RENDER_RECT_H
